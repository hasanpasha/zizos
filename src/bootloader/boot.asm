[ORG 0x7C00]
[bits 16]

JMP SHORT main
NOP

bdb_oem:                    DB  'MSWIN4.1'
bdb_bytes_per_sector:       DW  512
bdb_sectors_per_clustor:    DB  1
bdb_reserved_sectors:       DW  1
bdb_fat_count:              DB  2
bdb_dir_entries_count       DW  0x0E0
bdb_total_sectors:          DW  2880
bdb_media_descriptor_type   DB  0x0F0
bdb_sectors_per_fat         DW  9
bdb_sectors_per_track       DW  18
bdb_heads:                  DW  2
bdb_hidden_sectors:         DD  0
bdb_large_sector_count:     DD  0

; extended boot record
ebr_drive_number:           DB  0
                            DB  0
ebr_signature:              DB  0x29
ebr_volume_id:              DB  0x12, 0x34, 0x56, 0x78
ebr_volume_label:           DB  '   ZIZ OS   ' ; space left intentionally, [must be 12 bytes]
ebr_system_id               DB  'FAT12   ' ; must be 8 bytes

main:
    MOV ax, 0
    MOV ds, ax
    MOV es, ax
    MOV ss, ax

    MOV sp, 0x7C00

    MOV si, os_boot_msg
    CALL print

    ; 4 segments
    ; reserved segment: 1 sector
    ; FAT: 9 * 2 = 18 sectors [bdb_sectors_per_fat*bdb_fat_count]
    ; Root directory:
    ; Data

    MOV ax, [bdb_sectors_per_fat]
    MOV bl, [bdb_fat_count]
    XOR bh, bh
    MUL bx
    ADD ax, [bdb_reserved_sectors] ; LBA of the root directory
    PUSH ax

    MOV ax, [bdb_dir_entries_count]
    SHL ax, 5   ; ax *= 2**5
    XOR dx, dx
    DIV word[bdb_bytes_per_sector] ; (32 * num of entries) / bytes per sector

    TEST dx, dx
    JZ root_dir_after
    INC ax

root_dir_after:
    MOV cl, al
    POP ax
    MOV dl, [ebr_drive_number]
    MOV bx, buffer
    CALL disk_read

    XOR bx,bx
    MOV di, buffer

kernel_search:
    ; XOR si, si
    MOV si, file_kernel_bin
    MOV cx, 11
    PUSH di
    REPE CMPSB
    POP di
    JE kernel_found

    ADD di, 32  ; next dir
    INC bx
    CMP bx, [bdb_dir_entries_count]
    JL kernel_search

    JMP kernel_not_found

kernel_not_found:
    MOV si, kernel_not_found_msg
    CALL print

    HLT
    JMP halt

kernel_found:
    MOV ax, [di+26] ; di=[address of kernel], 26=[offset to first logical cluster]
    MOV [kernel_cluster], ax

    MOV ax, [bdb_reserved_sectors]
    MOV bx, buffer
    MOV cl, [bdb_sectors_per_fat]
    MOV dl, [ebr_drive_number]

    CALL disk_read

    MOV bx, kernel_load_segment
    MOV es, bx
    MOV bx, kernel_load_offset

kernel_load_loop:
    MOV ax, [kernel_cluster]
    ADD ax, 31
    MOV cl, 1
    MOV dl, [ebr_drive_number]

    CALL disk_read

    ADD bx, [bdb_bytes_per_sector]

    MOV ax, [kernel_cluster] ; (kernel cluster * 3)/2
    MOV cx, 3
    MUL cx
    MOV cx, 2
    DIV cx

    MOV si, buffer
    ADD si, ax
    MOV ax, [ds:si]

    OR dx, dx
    JZ even

odd:
    SHR ax, 4
    JMP next_cluster_after
even:
    AND ax, 0x0FFF

next_cluster_after:
    CMP ax, 0x0FF8
    JAE kernel_read_finish

    MOV [kernel_cluster], ax
    JMP kernel_load_loop

kernel_read_finish:
    MOV dl, [ebr_drive_number]
    MOV ax, kernel_load_segment
    MOV ds, ax
    MOV es, ax

    JMP kernel_load_segment:kernel_load_offset

    HLT

halt:
    JMP halt

; input: LBA index in ax
; output:
;   cx [bits 0-5]: sector number
;   cx [bits 6-15]: cylinder
;   dh: head
lba_to_chs:
    PUSH ax
    PUSH dx

    XOR dx, dx
    DIV word[bdb_sectors_per_track] ; (LBA % sectors per track) + 1 <- sector
    INC dx  ; sector [remainder of the division goes into dx register]
    MOV cx, dx

    ; (LBA/sectors per track) % number of heads <- head
    ; (LBA / sectors per track) / number of heads <- cylinders
    XOR dx, dx
    DIV word[bdb_heads] 
    MOV dh, dl  ; head

    MOV ch, al
    SHL ah, 6
    OR cl, ah   ; cylinders

    POP ax
    MOV dl, al
    POP ax

    RET


disk_read:
    PUSH ax
    PUSH bx
    PUSH cx
    PUSH dx
    PUSH di

    CALL lba_to_chs

    MOV ah, 0x02
    MOV di, 3   ; counter

disk_read_retry:
    STC
    INT 0x13
    JNC disk_read_done

    CALL disk_read_reset

    DEC di
    TEST di, di
    JNZ disk_read_retry

disk_read_fail:
    MOV si, read_failure_msg
    CALL print
    HLT
    JMP halt

disk_read_reset:
    PUSHA
    MOV ah, 0
    STC
    INT 0x13
    JC disk_read_fail
    POPA
    RET

disk_read_done:
    POP di
    POP dx
    POP dx
    POP bx
    POP ax

    RET

print:
    PUSH si
    PUSH ax
    PUSH bx

print_loop:
    LODSB
    OR al, al
    JZ print_end

    MOV ah, 0x0E
    MOV bh, 0
    INT 0x10

    JMP print_loop

print_end:
    POP bx
    POP ax
    POP si
    RET


os_boot_msg: DB 'Loading...', 0x0D, 0x0A, 0
read_failure_msg DB 'Failed to read the disk!', 0x0D, 0x0A, 0
file_kernel_bin DB 'KERNEL  BIN'
kernel_not_found_msg DB 'KERNEL.BIN not found', 0x0D, 0x0A, 0
kernel_searching_msg DB 'searching for KERNEL.BIN', 0x0D, 0x0A, 0
kernel_cluster DW 0

kernel_load_segment EQU 0x2000
kernel_load_offset EQU 0

TIMES 510 - ( $ - $$ ) DB 0
DW 0xAA55

buffer:
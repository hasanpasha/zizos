SIM=qemu-system-i386
ASM=nasm
CC16=./tools/open-watcom/binl/wcc
CFLAGS16=-s -wx -ms -zl -zq
LD16=./tools/open-watcom/binl/wlink
ASM_FLAGS=-f obj
SRC_DIR=src
BOOT_LOADER_SRC_DIR=$(SRC_DIR)/bootloader
BUILD_DIR=build
KERNEL_BUILD_DIR=$(BUILD_DIR)/kernel

all: clean always image

#
# Floppy Image
#
image: $(BUILD_DIR)/main.img
$(BUILD_DIR)/main.img: boot kernel
	dd if=/dev/zero of=$@ bs=512 count=2880
	mkfs.fat -F 12 -n "ZIZOS" $@
	dd if=$(BUILD_DIR)/boot.bin of=$@ conv=notrunc
	mcopy -i $@ $(BUILD_DIR)/kernel.bin "::kernel.bin"

#
# Bootloader
#
boot: $(BUILD_DIR)/boot.bin
$(BUILD_DIR)/boot.bin: $(SRC_DIR)/bootloader/boot.asm
	$(ASM) $^ -f bin -o $@


#
# Kernel
#
kernel: $(BUILD_DIR)/kernel.bin
$(BUILD_DIR)/kernel.bin: main.o print.o c_main.o stdio.o
	$(LD16) NAME $@ FILE \{$(KERNEL_BUILD_DIR)/asm/main.o $(KERNEL_BUILD_DIR)/asm/print.o $(KERNEL_BUILD_DIR)/c/main.o $(KERNEL_BUILD_DIR)/c/stdio.o \} OPTION MAP=$(BUILD_DIR)/kernel.map @$(SRC_DIR)/kernel/linker.lnk


main.o: $(KERNEL_BUILD_DIR)/asm/main.o
$(KERNEL_BUILD_DIR)/asm/main.o: $(SRC_DIR)/kernel/main.asm
	$(ASM) $(ASM_FLAGS) -o $@ $^

print.o: $(KERNEL_BUILD_DIR)/asm/print.o
$(KERNEL_BUILD_DIR)/asm/print.o: $(SRC_DIR)/kernel/print.asm
	$(ASM) $(ASM_FLAGS) -o $@ $^

c_main.o: $(KERNEL_BUILD_DIR)/c/main.o
$(KERNEL_BUILD_DIR)/c/main.o: $(SRC_DIR)/kernel/main.c
	$(CC16) $(CFLAGS16) -fo=$@ $^

stdio.o: $(KERNEL_BUILD_DIR)/c/stdio.o
$(KERNEL_BUILD_DIR)/c/stdio.o: $(SRC_DIR)/kernel/stdio.c
	$(CC16) $(CFLAGS16) -fo=$@ $^

always:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(KERNEL_BUILD_DIR)
	mkdir -p $(KERNEL_BUILD_DIR)/asm
	mkdir -p $(KERNEL_BUILD_DIR)/c

.PHONY = run
run: all
	$(SIM) -fda $(BUILD_DIR)/main.img

.PHONY = clean
clean:
	rm -vrf $(BUILD_DIR)/*

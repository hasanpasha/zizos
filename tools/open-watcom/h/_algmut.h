///////////////////////////////////////////////////////////////////////////
// FILE: _algmut.h (Definitions of mutating sequence operations)
//
// =========================================================================
//
//                          Open Watcom Project
//
// Copyright (c) 2004-2024 The Open Watcom Contributors. All Rights Reserved.
//
//    This file is automatically generated. Do not edit directly.
//
// =========================================================================
//
// Description: This header is part of the <algorithm> header.
///////////////////////////////////////////////////////////////////////////
#ifndef __ALGMUT_H_INCLUDED
#define __ALGMUT_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef _ALGORITHM_INCLUDED
 #error The header _algmut.h requires algorithm.
#endif

#ifndef _CSTDLIB_INCLUDED
 #include <cstdlib>
#endif

#ifndef _ITERATOR_INCLUDED
 #include <iterator>
#endif

namespace std {

    // copy( InputIterator, InputIterator, OutputIterator )
    // ****************************************************
    template< class InputIterator, class OutputIterator >
    OutputIterator copy( InputIterator first, InputIterator last, OutputIterator result )
    {
        while( first != last ) {
            *result = *first;
            ++first;
            ++result;
        }
        return( result );
    }

    // copy_backward( Bidirectional1, Bidirectional1, Bidirectional2 )
    // ****************************************************************
    template< class Bidirectional1, class Bidirectional2 >
    Bidirectional2 copy_backward( Bidirectional1 first,
                                  Bidirectional1 last,
                                  Bidirectional2 result )
    {
        if( first == last ) return( result );
        while( --last != first ) {
            *--result = *last;
        }
        *--result = *last;
        return( result );
    }

    // swap( Type &, Type & )
    // **********************
    template< class Type >
    inline void swap( Type &x, Type &y )
        { Type tmp(x); x = y; y = tmp; }


    // swap_ranges( ForwardIterator1, ForwardIterator1, ForwardIterator2 )
    // *******************************************************************
    template< class ForwardIterator1, class ForwardIterator2 >
    ForwardIterator2 swap_ranges( ForwardIterator1 first1,
                                  ForwardIterator1 last1,
                                  ForwardIterator2 first2 )
    {
        while( first1 != last1 ) {
            swap( *first1, *first2 ); // iter_swap? See 25.2.2p3
            ++first1;
            ++first2;
        }
        return( first2 );
    }

    // iter_swap( ForwardIterator1, ForwardIterator2 )
    // ***********************************************
    template< class ForwardIterator1, class ForwardIterator2 >
    inline void iter_swap( ForwardIterator1 x, ForwardIterator2 y )
    {
        iterator_traits< ForwardIterator1 >::value_type tmp(*x);
        *x = *y;
        *y = tmp;
    }

    // transform( InputIterator, InputIterator, OutputIterator, UnaryOperation )
    // *************************************************************************
    template< class InputIterator, class OutputIterator, class UnaryOperation >
    OutputIterator transform( InputIterator  first,
                              InputIterator  last,
                              OutputIterator result,
                              UnaryOperation op )
    {
        while( first != last ) {
            *result = op( *first );
            ++first;
            ++result;
        }
        return( result );
    }

    // transform( Input1, Input1, Input2, Output, BinaryOperation )
    // ************************************************************
    template< class InputIterator1,
              class InputIterator2,
              class OutputIterator,
              class BinaryOperation >
    OutputIterator transform( InputIterator1 first1,
                              InputIterator1 last1,
                              InputIterator2 first2,
                              OutputIterator result,
                              BinaryOperation bop )
    {
        while( first1 != last1 ) {
            *result = bop( *first1, *first2 );
            ++first1;
            ++first2;
            ++result;
        }
        return( result );
    }

    // replace( ForwardIterator, ForwardIterator, const Type &, const Type & )
    // ***********************************************************************
    template< class ForwardIterator, class Type >
    void replace( ForwardIterator first,
                  ForwardIterator last,
                  const Type &old_value,
                  const Type &new_value )
    {
        while( first != last ) {
            if( *first == old_value ) *first = new_value;
            ++first;
        }
    }

    // replace_if( ForwardIterator, ForwardIterator, Predicate, const Type & )
    // ***********************************************************************
    template< class ForwardIterator, class Predicate, class Type >
    void replace_if( ForwardIterator first,
                     ForwardIterator last,
                     Predicate pred,
                     const Type &new_value )
    {
        while( first != last ) {
            if( pred( *first ) != false )
                *first = new_value;
            ++first;
        }
    }

    // replace_copy( Input, Input, Output, const Type &, const Type & )
    // ****************************************************************
    template< class InputIterator, class OutputIterator, class Type >
    OutputIterator replace_copy( InputIterator  first,
                                 InputIterator  last,
                                 OutputIterator result,
                                 const Type &old_value,
                                 const Type &new_value )
    {
        while( first != last ) {
            *result = ( *first == old_value ) ? new_value : *first;
            ++first;
            ++result;
        }
        return( result );
    }

    // replace_copy_if( Input, Input, Output, Predicate, const Type & )
    // ****************************************************************
    template< class InputIterator, class OutputIterator, class Predicate, class Type >
    OutputIterator replace_copy_if( InputIterator  first,
                                    InputIterator  last,
                                    OutputIterator result,
                                    Predicate      pred,
                                    const Type &new_value )
    {
        while( first != last ) {
            *result = ( pred( *first ) ) ? new_value : *first;
            ++first;
            ++result;
        }
        return( result );
    }

    // fill( ForwardIterator, ForwardIterator, const Type & )
    // ******************************************************
    template< class ForwardIterator, class Type >
    void fill( ForwardIterator first, ForwardIterator last, const Type &value )
    {
        while( first != last ) {
            *first = value;
            ++first;
        }
    }

    // fill_n( OutputIterator, Size, const Type & )
    // ********************************************
    template< class OutputIterator, class Size, class Type >
    void fill_n( OutputIterator first, Size n, const Type &value )
    {
        unsigned long long i = 0ULL, max(n);
        while( i < max ) {
            *first = value;
            ++first;
            ++i;
        }
    }

    // generate( ForwardIterator, ForwardIterator, Generator )
    // *******************************************************
    template< class ForwardIterator, class Generator >
    void generate( ForwardIterator first, ForwardIterator last, Generator gen )
    {
        while( first != last ) {
            *first = gen( );
            ++first;
        }
    }

    // generate_n( OutputIterator, Size, Generator )
    // *********************************************
    template< class OutputIterator, class Size, class Generator >
    void generate_n( OutputIterator first, Size n, Generator gen )
    {
        unsigned long long i = 0ULL, max(n);
        while( i < max ) {
            *first = gen( );
            ++first;
            ++i;
        }
    }

    // remove( ForwardIterator, ForwardIterator, Type const & )
    // ********************************************************
    template< class ForwardIterator, class Type >
    ForwardIterator remove( ForwardIterator first, ForwardIterator last, Type const & value)
    {
        ForwardIterator out = first;
        bool copy = false;
        while( first != last) {
            if( *first == value ) {
                ++first;
                copy = true;
            } else {
                if( copy ) {
                    // Avoid unecessary copies.
                    *out = *first;
                }
                ++first;
                ++out;
            }
        }
        return( out );
    }

    // remove_if( ForwardIterator, ForwardIterator, Predictate )
    // *********************************************************
    template< class ForwardIterator, class Predictate >
    ForwardIterator remove_if( ForwardIterator first,
                               ForwardIterator last,
                               Predictate      pred )
    {
        ForwardIterator out = first;
        bool copy = false;
        while( first != last) {
            if( pred( *first ) != false ) {
                ++first;
                copy = true;
            } else {
                if( copy ){
                    // Avoid unecessary copies.
                    *out = *first;
                }
                ++first;
                ++out;
            }
        }
        return( out );
    }

    // remove_copy( InputIterator, InputIterator, OutputIterator, Type const & )
    // *************************************************************************
    template< class InputIterator, class OutputIterator, class Type >
    OutputIterator remove_copy( InputIterator  first,
                                InputIterator  last,
                                OutputIterator out,
                                Type const & value )
    {
        while( first != last) {
            if( *first == value ) {
                ++first;
            } else {
                *out = *first;
                ++first;
                ++out;
            }
        }
        return( out );
    }

    // remove_copy_if( InputIterator, InputIterator, OutputIterator, Predictate )
    // **************************************************************************
    template< class InputIterator, class OutputIterator, class Predictate >
    OutputIterator remove_copy_if( InputIterator  first,
                                   InputIterator  last,
                                   OutputIterator out,
                                   Predictate     pred )
    {
        while( first != last) {
            if( pred( *first ) != false ) {
                ++first;
            } else {
                *out = *first;
                ++first;
                ++out;
            }
        }
        return( out );
    }

    // unique( ForwardIterator, ForwardIterator )
    // ******************************************
    template< class ForwardIterator >
    ForwardIterator unique( ForwardIterator first, ForwardIterator last )
    {
        if( first == last ) return last;
        ForwardIterator probe( first );
        ++probe;

        while( probe != last ) {
            if( !( *first == *probe ) ) {
                ++first;
                if( first != probe ) *first = *probe;
            }
            ++probe;
        }
        ++first;
        return( first );
    }

    // unique( ForwardIterator, ForwardIterator, BinaryPredicate )
    // ***********************************************************
    template< class ForwardIterator, class BinaryPredicate >
    ForwardIterator unique( ForwardIterator first, ForwardIterator last, BinaryPredicate pred )
    {
        if( first == last ) return last;
        ForwardIterator probe( first );
        ++probe;

        while( probe != last ) {
            if( !pred( *first, *probe ) ) {
                ++first;
                if( first != probe ) *first = *probe;
            }
            ++probe;
        }
        ++first;
        return( first );
    }

    // unique_copy( InputIterator, InputIterator, OutputIterator )
    // ***********************************************************
    template< class InputIterator, class OutputIterator >
    OutputIterator unique_copy( InputIterator first, InputIterator last, OutputIterator result )
    {
        if( first == last ) return result;
        iterator_traits< InputIterator >::value_type temp( *first );
        ++first;
        *result++ = temp;

        while( first != last ) {
            if( !( temp == *first ) ) {
                temp = *first;
                *result++ = temp;
            }
            ++first;
        }
        return( result );
    }

    // unique_copy(InputIterator, InputIterator, OutputIterator, BinaryPredicate )
    // ***************************************************************************
    template< class InputIterator, class OutputIterator, class BinaryPredicate >
    OutputIterator unique_copy( InputIterator   first,
                                InputIterator   last,
                                OutputIterator  result,
                                BinaryPredicate pred )
    {
        if( first == last ) return result;
        iterator_traits< InputIterator >::value_type temp( *first );
        ++first;
        *result++ = temp;

        while( first != last ) {
            if( !pred( temp, *first ) ) {
                temp = *first;
                *result++ = temp;
            }
            ++first;
        }
        return( result );
    }

    // reverse( Bidirectional, Bidirectional )
    // ***************************************
    template< class Bidirectional >
    void reverse( Bidirectional first, Bidirectional last )
    {
        if( first == last ) return;
        --last;
        while( first != last ) {
            swap( *first, *last );
            ++first;
            if( first == last ) break;
            --last;
        }
    }

    // reverse_copy( Bidirectional, Bidirectional, OutputIterator )
    // ************************************************************
    template< class Bidirectional, class OutputIterator >
    OutputIterator reverse_copy( Bidirectional first, Bidirectional last, OutputIterator result )
    {
        if( first == last ) return( result );
        while( --last != first ) {
            *result = *last;
            ++result;
        }
        *result = *last;
        return( ++result );
    }

    // random_shuffle( RandomAccess, RandomAccess )
    // ********************************************
    template< class RandomAccess >
    void random_shuffle( RandomAccess first, RandomAccess last )
    {
        typedef typename iterator_traits< RandomAccess >::difference_type Int;
        Int length = last - first;
        Int i = 1;

        while( i < length ) {
            swap( first[i], first[ rand( ) % ( i + 1 ) ] );
            ++i;
        }
    }

    // random_shuffle( RandomAccess, RandomAccess, RandomGenerator >
    // *************************************************************
    template< class RandomAccess, class RandomGenerator >
    void random_shuffle( RandomAccess first, RandomAccess last, RandomGenerator rgen )
    {
        typedef typename iterator_traits< RandomAccess >::difference_type Int;
        Int length = last - first;
        Int i = 1;

        while( i < length ) {
            swap( first[i], first[ rgen( i + 1 ) ] );
            ++i;
        }
    }

} // namespace std

#endif

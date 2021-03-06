//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGICAL_OR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGICAL_OR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-boolean
    This function object returns the return the logical or of the two arguments

    The operands must share the same @ref cardinal_of value.

    Infix notation can be used with operator '||'

    @warningbox{Take care that using && in scalar mode does short-circuit and does not in simd mode.}


    @par Header <boost/simd/function/logical_or.hpp>

   @par Example:

     @snippet logical_or.cpp logical_or

   @par Possible output:

     @snippet logical_or.txt logical_or

  **/
  as_logical_t<Value0> logical_or(Value0 const& x, Value1 const& y);
} }
#endif

#include <boost/simd/function/scalar/logical_or.hpp>
#include <boost/simd/function/simd/logical_or.hpp>

#endif

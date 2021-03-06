//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOT_INC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOT_INC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-boolean
    This function object conditionally returns  @c x (respectively @c x+1)
    if @c c is @ref True (respectively  @ref False)


    @par Header <boost/simd/function/ifnot_inc.hpp>

   @par Example:

     @snippet ifnot_inc.cpp ifnot_inc

   @par Possible output:

     @snippet ifnot_inc.txt ifnot_inc

  **/
  Value ifnot_inc(Value const& c, Value const& x);

  /*!
    @overload
  */
  Value ifnot_inc(LogicalValue const& c, Value const& x);
} }
#endif

#include <boost/simd/function/scalar/ifnot_inc.hpp>
#include <boost/simd/function/simd/ifnot_inc.hpp>

#endif

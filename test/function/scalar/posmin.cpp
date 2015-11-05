//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/posmin.hpp>
#include <simd_test.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>


STF_CASE_TPL (" posmax",  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::posmin;
  using r_t = decltype(posmin(T()));

  // specific values tests
  STF_ULP_EQUAL(posmin(bs::Inf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(posmin(bs::Minf<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(posmin(bs::Mone<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(posmin(bs::Nan<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(posmin(bs::One<T>()), bs::Zero<r_t>(), 0);
  STF_ULP_EQUAL(posmin(bs::Zero<T>()), bs::Zero<r_t>(), 0);
}
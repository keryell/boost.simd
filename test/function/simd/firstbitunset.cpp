//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/firstbitunset.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <simd_test.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/signmask.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using p_t = bs::pack<T, N>;
  using iT =  bd::as_integer_t<T, unsigned>;
  using pi_t = bs::pack<iT, N>;

  T a1[N];
  iT b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
     a1[i] = T(i+1);
     b[i] = bs::firstbitunset(a1[i]);
   }
  p_t aa1(&a1[0], &a1[0]+N);
  pi_t bb(&b[0], &b[0]+N);
  STF_EQUAL(bs::firstbitunset(aa1), bb);
}

STF_CASE_TPL("Check firstbitunset on pack" ,  STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}

STF_CASE_TPL (" firstbitunsetreal",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using bs::firstbitunset;
  using p_t = bs::pack<T>;
  using r_t = decltype(firstbitunset(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, (bd::as_integer_t<p_t, unsigned>));

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(firstbitunset(bs::Inf<p_t>()), bs::One<r_t>());
  STF_EQUAL(firstbitunset(bs::Minf<p_t>()), bs::One<r_t>());
  STF_EQUAL(firstbitunset(bs::Nan<p_t>()), bs::Zero<r_t>());
#endif
  STF_EQUAL(firstbitunset(bs::Signmask<p_t>()), bs::One<r_t>());
  STF_EQUAL(firstbitunset(bs::Zero<p_t>()), bs::One<r_t>());
} // end of test for floating_


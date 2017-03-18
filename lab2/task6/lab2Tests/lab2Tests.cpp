#include "stdafx.h"
#include "../lab2_task2/PrimeNumbers.h"

using namespace std;

BOOST_AUTO_TEST_CASE(NoPrimeNumbers)
{
	IntegerSet ans = GeneratePrimeNumbers(1);
	BOOST_CHECK_EQUAL(ans.size(), 0u);
}

BOOST_AUTO_TEST_CASE(SomePrimeNumbers)
{
	IntegerSet ans = GeneratePrimeNumbers(9);
	IntegerSet rightAns = { 2, 3, 5, 7 };
	BOOST_CHECK_EQUAL(ans, rightAns);
}

BOOST_AUTO_TEST_CASE(BigCountOfPrimeNumbers) //First 500 prime numbers
{
	IntegerSet ans = GeneratePrimeNumbers(3571);
	BOOST_CHECK_EQUAL(ans.size(), 500u);
}
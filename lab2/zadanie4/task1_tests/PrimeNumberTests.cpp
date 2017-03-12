#include "stdafx.h"
#include "..\task1\PrimeNumbers.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(ProcessVector_function)


	BOOST_AUTO_TEST_CASE(count_prime_numbers_in_0)
	{
		unsigned int givenBound = 0;
		std::set<int> primeNumbers = {};
		auto primeNumbersSet = GeneratePrimeNumbersSet(givenBound);
		BOOST_CHECK(primeNumbers == primeNumbersSet); 
	}

	BOOST_AUTO_TEST_CASE(count_prime_numbers_in_1)
	{
		unsigned int givenBound = 1;
		std::set<int> primeNumbers = {};
		auto primeNumbersSet = GeneratePrimeNumbersSet(givenBound);
		BOOST_CHECK(primeNumbers == primeNumbersSet);
	}

	BOOST_AUTO_TEST_CASE(count_prime_numbers_in_2)
	{
		unsigned int givenBound = 2;
		std::set<int> primeNumbers = { 2 };
		auto primeNumbersSet = GeneratePrimeNumbersSet(givenBound);
		BOOST_CHECK(primeNumbers == primeNumbersSet);
	}

	BOOST_AUTO_TEST_CASE(count_prime_numbers_in_3)
	{
		unsigned int givenBound = 3;
		std::set<int> primeNumbers = { 2, 3 };
		auto primeNumbersSet = GeneratePrimeNumbersSet(givenBound);
		BOOST_CHECK(primeNumbers == primeNumbersSet);
	}

	BOOST_AUTO_TEST_CASE(count_prime_numbers_in_10)
	{
		unsigned int givenBound = 10;
		std::set<int> primeNumbers = { 2, 3, 5, 7 };
		std::set<int> primeNumbersSet = GeneratePrimeNumbersSet(givenBound);
		BOOST_CHECK(primeNumbers == primeNumbersSet);
	}

	BOOST_AUTO_TEST_CASE(count_prime_numbers_in_100_000_000)
	{
		unsigned int givenBound = 100000000;
		unsigned int rightAmountOfPrimeNumbers = 5'761'455;
		std::set<int> primeNumbersSet = GeneratePrimeNumbersSet(givenBound);
		unsigned int AmountOfPrimeNumbers = primeNumbersSet.size();
		BOOST_CHECK(rightAmountOfPrimeNumbers == AmountOfPrimeNumbers);
	}

BOOST_AUTO_TEST_SUITE_END()



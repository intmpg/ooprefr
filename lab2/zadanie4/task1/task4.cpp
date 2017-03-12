#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>
#include "PrimeNumbers.h"

using namespace std;

int _tmain()
{
	unsigned int givenBound = GetUpperBound();

	auto primeNumbersSet = GeneratePrimeNumbersSet(givenBound);

	cout << "Count of Prime Numbers:" << primeNumbersSet.size() << endl;

	if (DoYouWantToWritePrimeNumbers())
		WriteAllPrimeNumbers(primeNumbersSet);

	return 0;
}


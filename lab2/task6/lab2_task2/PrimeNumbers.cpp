#include "stdafx.h"
#include "PrimeNumbers.h"

IntegerSet GeneratePrimeNumbers(int upperBound)
{
	IntegerSet res;

	int *lowestPrime = new int[upperBound + 1];
	memset(lowestPrime, 0, sizeof(int) * (upperBound + 1));
	for (int i = 2; i <= upperBound; i++)
	{
		if (lowestPrime[i] == 0)
		{
			lowestPrime[i] = i;
			res.insert(i);
		}
		for (int x : res)
		{
			if (x > lowestPrime[i] || (1LL * i * x > upperBound))
			{
				break;
			}
			lowestPrime[i * x] = x;	
		}
	}
	delete[] lowestPrime;

	return res;
}
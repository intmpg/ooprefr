#include "stdafx.h"
#include "PrimeNumbers.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Not enough arguments\n");
		return 0;
	}

	char *pEnd;
	int upperBound = strtol(argv[1], &pEnd, 10);
	if (*pEnd != '\0' || !strlen(argv[1]))
	{
		printf("Wrong number\n");
		return 1;
	}

	IntegerSet ans = GeneratePrimeNumbers(upperBound);
	for (int x : ans)
	{
		printf("%d ", x);
	}

	return 0;
}


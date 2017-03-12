#include "stdafx.h"
#include "PrimeNumbers.h"

using namespace std;

void WriteAllPrimeNumbers(set<int> const & primeNumbersSet)
{
	for (auto & it : primeNumbersSet)
	{
		cout << it << "; ";
	}
}

bool DoYouWantToWritePrimeNumbers()
{
	string answerToQuestion;
	while (answerToQuestion != "y" && answerToQuestion != "n")
	{
		cout << "Do you want to see all prime numbers? y/n ";
		cin >> answerToQuestion;
		if (answerToQuestion == "y")
			return 1;
		else
			if (answerToQuestion != "n")
				cout << "Try again" << endl;
	}
	return 0;
}

int GetUpperBound()
{
	string numberString;
	unsigned int x;
	cout << "input number:";
	cin >> x;
	return x;
}

set<int> SelectPrimeNumbers(vector<bool> arrayOfNumbers, unsigned int givenBound)
{
	set<int> primeNumbersSet;
	for (size_t i = 2; i <= givenBound; i++)
		if (arrayOfNumbers[i])
		{
			primeNumbersSet.insert(i);
		}
	return primeNumbersSet;
}

set<int> GeneratePrimeNumbersSet(unsigned int const & givenBound)
{	
	vector<bool> arrayOfNumbers(givenBound+1, true);

	for (size_t i = 2; (i * i) <= givenBound; i++)
	{
		if (arrayOfNumbers[i])
			for (size_t k = i*i; k <= givenBound; k += i)
				arrayOfNumbers[k] = false;
	}
	return SelectPrimeNumbers(arrayOfNumbers, givenBound);
}
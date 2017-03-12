// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "VectorProcessor.h"

using namespace std;

int _tmain()
{
	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
	
	ProcessVector(numbers);

	std::sort(numbers.begin(), numbers.end());

	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));

	return 0;
}


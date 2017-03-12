#pragma once
#include <string>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)
#include <boost/algorithm/string.hpp>

using namespace std;

const int UPPERBOUND = 1000'000'000;

int GetUpperBound();
bool DoYouWantToWritePrimeNumbers();
void WriteAllPrimeNumbers(set<int> const & primeNumbersSet);
set<int> SelectPrimeNumbers(vector<bool> arrayOfNumbers, unsigned int givenBound);
set<int> GeneratePrimeNumbersSet(unsigned int const & givenBound);
#pragma once
#include "stdafx.h"

struct Athlete
{
	std::string name;
	std::string surname;
	std::string middleName;
	double weight;
	double growth;
};
 
Athlete CreateAthlete(std::string const & str)
{
	std::istringstream strm(str);
	Athlete athlete;
	strm >> athlete.name;
	strm >> athlete.middleName;
	strm >> athlete.surname;
	strm >> athlete.weight;
	strm >> athlete.growth;
	return athlete;
}

template <typename T, typename Less = std::less<T> >
bool FindMax(const std::vector<T> &arr, T& maxValue, const Less &less = Less())
{
	if (arr.empty())
	{
		return false;
	}

	auto max = arr.begin();
	for (auto it = arr.begin() + 1; it != arr.end(); it++)
	{
		if (less(*max, *it))
		{
			max = it;
		}
	}
	
	maxValue = *max;
	return true;
};

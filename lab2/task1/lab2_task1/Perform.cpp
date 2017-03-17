#include "stdafx.h"
#include "Perform.h"

void Perform(vf &a)
{
	if (!a.size())
	{
		return;
	}
	auto res = minmax_element(a.begin(), a.end());
	float min = *res.first, max = *res.second;
	float product = min * max;
	transform(a.begin(), a.end(), a.begin(), [product](float n) -> float
	{
		return (n < 0) ? n * product : n;
	});
}
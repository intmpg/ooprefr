#include "stdafx.h"
#include "VectorProcessor.h"
#include <algorithm>
#include <numeric>
#include <functional>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;
using namespace std::placeholders;
using namespace boost::phoenix::placeholders;
using namespace boost::phoenix;
using boost::transform;

void ProcessVector(std::vector<double> & numbers)
{
	if (numbers.size())
	{
		vector<double>::iterator minElem = min_element(numbers.begin(), numbers.end());

		boost::transform(numbers, numbers.begin(), arg1 * *minElem);
	}
}
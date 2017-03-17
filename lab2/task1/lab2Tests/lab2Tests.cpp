#include "stdafx.h"
#include "../lab2_task1/Perform.h"

bool VectorsAreEqual(const vf &x, const vf &y)
{
	return x == y;
}

BOOST_AUTO_TEST_CASE(EmptyVector)
{
	vf emptyVector;
	Perform(emptyVector);
	BOOST_CHECK(emptyVector.empty());
}

BOOST_AUTO_TEST_CASE(VectorWithNoNegativeElements)
{
	vf numbers = { 0.0f, 1.0f, 0.2f, 4.0f };
	Perform(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { 0.0f, 1.0f, 0.2f, 4.0f }));
}

BOOST_AUTO_TEST_CASE(VectorWithEqualMinAndMaxElements)
{
	vf numbers = { -3.0f, -3.0f, -3.0f };
	Perform(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { -27.0f, -27.0f, -27.0f }));
}

BOOST_AUTO_TEST_CASE(VectorWithDifferentMinAndMaxElements)
{
	vf numbers = { -4.0f, 1.2f, 3.5f, 7.0f };
	Perform(numbers);
	BOOST_CHECK(VectorsAreEqual(numbers, { 112.0f, 1.2f, 3.5f, 7.0f }));
}

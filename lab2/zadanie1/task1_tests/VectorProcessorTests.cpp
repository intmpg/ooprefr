#include "stdafx.h"
#include "..\task1\VectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

	// Создает пустой вектор из пустого вектора
	BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		ProcessVector(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}

	BOOST_AUTO_TEST_CASE(processing_a_vector_with_only_one_element)
	{
		vector<double> numbers = { 2 };
		const double minElem = 2;
		ProcessVector(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers,
		{ (2 * minElem) }
		));
	}

	// при обработке вектора с несколькими одинаковыми элементами
	BOOST_AUTO_TEST_CASE(processing_a_vector_with_same_elements)
	{
		vector<double> numbers = { 2, 2, 2 };
		const double minElem = 2;
		ProcessVector(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers,
		{ (2 * minElem), (2 * minElem), (2 * minElem) }
		));
	}

	// при обработке вектора с одним отрицательным
	BOOST_AUTO_TEST_CASE(there_is_at_least_one_element_is_less_than_all_the_rest)
		// должен умножить на это число каждый элемент вектора
	{
		vector<double> numbers = { -1, 3.5, 4, -2 };
		ProcessVector(numbers);

		BOOST_CHECK(VectorsAreEqual(numbers,
		{ (-1 * -2), (3.5 * -2), (4 * -2), (-2 * -2) }
		));
	}

BOOST_AUTO_TEST_SUITE_END()



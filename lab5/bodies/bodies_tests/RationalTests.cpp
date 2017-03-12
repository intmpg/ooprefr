#include "stdafx.h"
#include "../Rational.h"

void VerifyRational(const CRational & rational, int expectedNumerator, int expectedDenominator, double expectedDivisionResult)
{
	BOOST_CHECK_EQUAL(rational.GetNumerator(), expectedNumerator);
	BOOST_CHECK_EQUAL(rational.GetDenominator(), expectedDenominator);
	BOOST_CHECK_EQUAL(rational.ToDouble(), expectedDivisionResult);
}

BOOST_AUTO_TEST_SUITE(Rational_number)
	BOOST_AUTO_TEST_CASE(is_0_when_empty)
	{
		VerifyRational(CRational(), 0, 1, 0);
	}
	BOOST_AUTO_TEST_CASE(can_be_launched_from_integer_number)
	{
		VerifyRational(CRational(10), 10, 1, 10);
		VerifyRational(CRational(-10), -10, 1, -10);
	}
BOOST_AUTO_TEST_SUITE_END()
//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать унарный + и унарный -
// Указание: см. материалы к лекции
// Пример использования:
//	const CRational r1(3, 5);
//	CRational r2 = -r1; // r2 должно стать -3/5
//	assert(r2.GetNumerator(), -3);
//	assert(r2.GetDenominator(), 5);
//	CRational r3 = +r2; // r3 также равно -3/5
//	assert(r3.GetNumerator(), -3);
//	assert(r3.GetDenominator(), 5);
// Унарный минус возвращает раицональное число без знака
// Унарный плюс возвращает рациональное число, равное текущему
// Реализация не должна допускать операции вроде:
//  -someRational = someOtherRational;
//	+someRational = someOtherRational;
//////////////////////////////////////////////////////////////////////////

struct UnaryOperationFixture
{
	CRational rational1;
	UnaryOperationFixture()
		: rational1(2, 7)
	{}
};

BOOST_FIXTURE_TEST_SUITE(unary_operation, UnaryOperationFixture)
BOOST_AUTO_TEST_CASE(unary_plus)
{
	auto rational2 = +rational1;
	VerifyRational(rational2, 2, 7, 0.28571428571428571428571428571429);
}
BOOST_AUTO_TEST_CASE(unary_minus)
{
	auto rational2 = -rational1;
	VerifyRational(rational2, -2, 7, -0.28571428571428571428571428571429);
}
BOOST_AUTO_TEST_CASE(unary_plus_with_unary_minus)
{
	auto rational2 = -rational1;
	auto rational3 = +rational2;
	VerifyRational(rational2, -2, 7, -0.28571428571428571428571428571429);
}
BOOST_AUTO_TEST_CASE(unary_minus_with_unary_minus)
{
	auto rational2 = -rational1;
	auto rational3 = -rational2;
	VerifyRational(rational3, 2, 7, 0.28571428571428571428571428571429);
}
BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать бинарный +
// Возвращает результат сложения двух рациональных чисел, 
//	рационального числа с целым, целого числа с рациональным.
//	(1/2) + (1/6) = (2/3)
//	(1/2) + 1     = (3/2)
//	1 + (1/2)     = (3/2)
//////////////////////////////////////////////////////////////////////////

struct BinaryOperationFixture
{
	CRational rational1;
	BinaryOperationFixture()
		: rational1(1, 2)
	{}
};

BOOST_FIXTURE_TEST_SUITE(binary_plus_and_minus_operator, BinaryOperationFixture)
BOOST_AUTO_TEST_CASE(binary_plus_with_rational_number)
{
	auto rational2 = rational1 + CRational(1, 6);
	VerifyRational(rational2, 2, 3, 0.66666666666666666666666666666667);
}
BOOST_AUTO_TEST_CASE(binary_plus_with_unit)
{
	auto rational2 = rational1 + CRational(1);
	VerifyRational(rational2, 3, 2, 1.5);
}
BOOST_AUTO_TEST_CASE(binary_plus_with_negative_unit)
{
	auto rational2 = CRational(-1) + rational1;
	VerifyRational(rational2, -1, 2, -0.5);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный -
// Возвращает разность двух рациональных чисел, 
//	рационального числа и целого, либо целого числа и рационального:
//	(1/2) - (1/6) = (1/3)
//	(1/2) - 1     = (-1/2)
//	1 - (1/2)     = (1/2)
//////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(binary_minus_with_rational_number)
{
	auto rational2 = rational1 - CRational(1, 6);
	VerifyRational(rational2, 1, 3, 0.33333333333333333333333333333333);
}
BOOST_AUTO_TEST_CASE(binary_minus_with_unit)
{
	auto rational2 = rational1 - CRational(1);
	VerifyRational(rational2, -1, 2, -0.5);
}
BOOST_AUTO_TEST_CASE(binary_minus_with_negative_unit)
{
	auto rational2 = CRational(-1) - rational1;
	VerifyRational(rational2, -3, 2, -1.5);
}
BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать оператор +=
// Выполняет увеличение рационального числа на величину второго рационального,
//	либо целого числа:
//	(1/2) += (1/6)  → (2/3)
//	(1/2) += 1      → (3/2)
//////////////////////////////////////////////////////////////////////////


struct ConcatenationOperatorFixture
{
	CRational rational1;
	ConcatenationOperatorFixture()
		: rational1(3, 2)
	{}
};

BOOST_FIXTURE_TEST_SUITE(concatenation_operator, ConcatenationOperatorFixture)
BOOST_AUTO_TEST_CASE(concatenation_operator_with_rational_number)
{
	rational1 += CRational(1, 6);
	VerifyRational(rational1, 5, 3, 1.6666666666666666666666666666667);
}
BOOST_AUTO_TEST_CASE(concatenation_operator_with_unit)
{
	rational1 += CRational(1);
	VerifyRational(rational1, 5, 2, 2.5);
}
BOOST_AUTO_TEST_CASE(concatenation_operator_with_negative_rational_number)
{
	rational1 += CRational(-4, 5);
	VerifyRational(rational1, 7, 10, 0.7);
}
BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор -=
// Выполняет уменьшение рационального числа на величину второго рационального либо целого числа :
// (1/2) -= (1/6)  → (1/3)
// (1/2) -= 1      → (-1/2)
//////////////////////////////////////////////////////////////////////////

struct SubstractionOperatorFixture
{
	CRational rational1;
	SubstractionOperatorFixture()
		: rational1(3, 2)
	{}
};

BOOST_FIXTURE_TEST_SUITE(substraction_operator, SubstractionOperatorFixture)
BOOST_AUTO_TEST_CASE(substraction_operator_with_rational_number)
{
	rational1 -= CRational(1, 6);
	VerifyRational(rational1, 4, 3, 1.3333333333333333333333333333333);
}
BOOST_AUTO_TEST_CASE(substraction_operator_with_unit)
{
	rational1 -= CRational(1);
	VerifyRational(rational1, 1, 2, 0.5);
}
BOOST_AUTO_TEST_CASE(substraction_operator_with_negative_unit)
{
	rational1 -= CRational(-1);
	VerifyRational(rational1, 5, 2, 2.5);
}
BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор *
// Возвращает результат произведения рациональных чисел, 
//	рационального и целого, либо целого и рационального :
//	(1/2) * (2/3) = (1/3)
//	(1/2) * (-3)  = (-3/2)
//	(7*2) / 3     = (14/3)
//////////////////////////////////////////////////////////////////////////

struct MultiplyOperatorFixture
{
	CRational rational1;
	MultiplyOperatorFixture()
		: rational1(5, 6)
	{}
};

BOOST_FIXTURE_TEST_SUITE(multiply_operator, MultiplyOperatorFixture)
BOOST_AUTO_TEST_CASE(multiply_operator_with_rational_number)
{
	auto rational2 = rational1 * CRational(1, 6);
	VerifyRational(rational2, 5, 36, 0.13888888888888888888888888888889);
}
BOOST_AUTO_TEST_CASE(multiply_operator_with_unit)
{
	auto rational2 = rational1 * CRational(1);
	VerifyRational(rational2, 5, 6, 0.83333333333333333333333333333333);
}
BOOST_AUTO_TEST_CASE(multiply_operator_with_negative_rational_number)
{
	auto rational2 = rational1 * CRational(-1, 6);
	VerifyRational(rational2, -5, 36, -0.13888888888888888888888888888889);
}
BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор /
// Возвращает частное двух рациональных чисел, 
//	рационального и целого, целого и рационального :
//	(1/2) ⁄ (2/3) = (3/4)
//	(1/2) ⁄ 5     = (1/10)
//	7 ⁄ (2/3)     = (21/2)
//////////////////////////////////////////////////////////////////////////

struct DivisionOperatorFixture
{
	CRational rational1;
	DivisionOperatorFixture()
		: rational1(6, 5)
	{}
};

BOOST_FIXTURE_TEST_SUITE(division_operator, DivisionOperatorFixture)
BOOST_AUTO_TEST_CASE(division_operator_with_rational_number)
{
	auto rational2 = rational1 / CRational(1, 6);
	VerifyRational(rational2, 36, 5, 7.2);
}
BOOST_AUTO_TEST_CASE(division_operator_with_unit)
{
	auto rational2 = rational1 / CRational(1);
	VerifyRational(rational2, 6, 5, 1.2);
}
BOOST_AUTO_TEST_CASE(division_operator_with_negative_rational_number)
{
	auto rational2 = rational1 / CRational(-1, 6);
	VerifyRational(rational2, -36, 5, -7.2);
}
BOOST_AUTO_TEST_CASE(division_operator_with_five)
{
	auto rational2 = rational1 / CRational(5);
	VerifyRational(rational2, 6, 25, 0.24);
}
BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор *=
// Умножает значение первого рационального числа на другое рациональное, 
//	либо целое:
//	(1/2) *= (2/3) → (1/3)
//	(1/2) *= 3     → (3/2)
//////////////////////////////////////////////////////////////////////////


struct MultipliedOperatorFixture
{
	CRational rational1;
	MultipliedOperatorFixture()
		: rational1(7, 8)
	{}
};

BOOST_FIXTURE_TEST_SUITE(multiplied_and_division_operators, MultipliedOperatorFixture)
BOOST_AUTO_TEST_CASE(multiplied_operator_with_rational_number)
{
	rational1 *= CRational(2, 3);
	VerifyRational(rational1, 7, 12, 0.58333333333333333333333333333333);
}
BOOST_AUTO_TEST_CASE(multiplied_operator_with_third)
{
	rational1 *= CRational(3);
	VerifyRational(rational1, 21, 8, 2.625);
}
BOOST_AUTO_TEST_CASE(multiplied_operator_with_negative_rational_number)
{
	rational1 *= CRational(-1, 6);
	VerifyRational(rational1, -7, 48, -0.14583333333333333333333333333333);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор /=
// Делит первое рациональное число на другое рациональное, 
//	либо целое:
//	(1/2) /= (2/3) → (3/4)
//	(1/2) /= 3     → (1/6)
//////////////////////////////////////////////////////////////////////////


BOOST_AUTO_TEST_CASE(divisied_operator_with_rational_number)
{
	rational1 /= CRational(2, 3);
	VerifyRational(rational1, 21, 16, 1.3125);
}
BOOST_AUTO_TEST_CASE(divisied_operator_with_third)
{
	rational1 /= CRational(3);
	VerifyRational(rational1, 7, 24, 0.29166666666666666666666666666667);
}
BOOST_AUTO_TEST_CASE(divisied_operator_with_negative_rational_number)
{
	rational1 /= CRational(-1, 6);
	VerifyRational(rational1, -21, 4, -5.25);
}
BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать операторы == и !=
// Проверяют равенство (и неравенство) двух рациональных чисел, 
//	целого и рационального, рационального и целого:
//	(1/2) == (1/2) → true
//	(4/1) == 4     → true
//	3 == (3/1)     → true
//	(1/2) != (2/3) → true
//	(1/2) != 7     → true
//	3 != (2/3)     → true
//////////////////////////////////////////////////////////////////////////


struct ComparisonOperatorFixture
{
	CRational rational1;
	ComparisonOperatorFixture()
		: rational1(9, 5)
	{}
};

BOOST_FIXTURE_TEST_SUITE(compare_operator, ComparisonOperatorFixture)
BOOST_AUTO_TEST_CASE(comparison_operator_with_not_equal_numbers)
{
	BOOST_CHECK(!(rational1 == CRational(3, 4)));
}
BOOST_AUTO_TEST_CASE(equal_operator_with_equal_numbers)
{
	BOOST_CHECK(rational1 == CRational(9, 5));

}
BOOST_AUTO_TEST_CASE(not_equal_operator_with_equal_numbers)
{
	BOOST_CHECK(!(rational1 != CRational(9, 5)));

}
BOOST_AUTO_TEST_CASE(not_equal_operator_with_not_equal_numbers)
{
	BOOST_CHECK(rational1 != CRational(1, 2));

}

BOOST_AUTO_TEST_CASE(more_operator_with_less_number)
{
	BOOST_CHECK(rational1 > CRational(5, 4));
}
BOOST_AUTO_TEST_CASE(more_operator_with_more_number)
{
	BOOST_CHECK(!(rational1 > CRational(2)));
}
BOOST_AUTO_TEST_CASE(more_operator_with_equal_number)
{
	BOOST_CHECK(!(rational1 > CRational(9, 5)));
}
BOOST_AUTO_TEST_CASE(less_operator_with_unit)
{
	BOOST_CHECK(!(rational1 < CRational(1)));
}
BOOST_AUTO_TEST_CASE(less_operator_with_equal_number)
{
	BOOST_CHECK(!(rational1 < CRational(9, 5)));
}
BOOST_AUTO_TEST_CASE(less_operator_with_more_number)
{
	BOOST_CHECK(rational1 < CRational(2));
}

BOOST_AUTO_TEST_CASE(more_or_equal_operator_with_more_number)
{
	BOOST_CHECK(!(rational1 >= CRational(2)));
}
BOOST_AUTO_TEST_CASE(more_or_equal_operator_with_equal_number)
{
	BOOST_CHECK(rational1 >= CRational(9, 5));
}
BOOST_AUTO_TEST_CASE(more_or_equal_operator_with_less_number)
{
	BOOST_CHECK(rational1 >= CRational(1));
}

BOOST_AUTO_TEST_CASE(less_or_equal_operator_with_more_number)
{
	BOOST_CHECK(rational1 <= CRational(2));
}
BOOST_AUTO_TEST_CASE(less_or_equal_operator_with_equal_number)
{
	BOOST_CHECK(rational1 <= CRational(9, 5));
}
BOOST_AUTO_TEST_CASE(less_or_equal_operator_with_less_number)
{
	BOOST_CHECK(!(rational1 <= CRational(1)));
}

BOOST_AUTO_TEST_SUITE_END()

//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//	std::ostream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE(rational_integer_to_ostream)
{
	CRational rational(10,87);
	std::ostringstream strm;
	strm << rational;
	BOOST_CHECK_EQUAL(strm.str(), "10/87");
}

//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//	std::istream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////

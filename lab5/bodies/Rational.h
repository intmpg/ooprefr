#pragma once
#include "stdafx.h"

class CRational
{
public:
	//  онструирует рациональное число, равное нулю (0/1)
	CRational();

	//  онструирует рациональное число, равное value (value/1)
	CRational(int value);

	//  онструирует рациональное число, равное numerator/denominator
	// –ациональное число должно хранитьс€ в нормализованном виде:
	//	знаменатель положительный (числитель может быть отрицательным)
	//	числитель и знаменатель не имеютобщиз делителей (6/8 => 3/4 и т.п.)
	// ≈сли знаменатель равен нулю, должно сконструироватьс€ рациональное число, равное нулю
	CRational(int numerator, int denominator);

	// ¬озвращаетчислитель
	int GetNumerator()const;

	// ¬озвращает знаменатель (натуральное число)
	int GetDenominator()const;

	// ¬озвращает отношение числител€ и знаменател€ в виде числа double
	double ToDouble()const;



	std::pair<int, CRational> ToCompoundFraction() const;
	// task 1 unary + -
	CRational operator+ () const;
	CRational operator- () const;

	// task 4 +=
	CRational & operator +=(const CRational & rational2);

	// task 5 -=
	CRational & operator -=(const CRational & rational2);

	// task 8 *=
	CRational & operator *=(const CRational & rational2);

	// task 9 /=
	CRational & operator /=(const CRational & rational2);

private:
	int m_numerator;
	int m_denominator;

	void Normalize();

	unsigned GCD(unsigned a, unsigned b);
};

//task 2
CRational const operator+ (CRational const &rational1, CRational const &rational2);

//task 3
CRational const operator- (CRational const &rational1, CRational const &rational2);

//task 6
CRational const operator* (CRational const &rational1, CRational const &rational2);

//task 7
CRational const operator/ (CRational const &rational1, CRational const &rational2);

// task 10 == and !=
bool const operator ==(const CRational & rational1, const CRational & rational2);
bool const operator !=(const CRational & rational1, const CRational & rational2);

// task 11 <, <=, >, >=
bool const operator <(const CRational & rational1, const CRational & rational2);
bool const operator <=(const CRational & rational1, const CRational & rational2);
bool const operator >(const CRational & rational1, const CRational & rational2);
bool const operator >=(const CRational & rational1, const CRational & rational2);

// task 13 ostream
std::ostream & operator <<(std::ostream & strm, const CRational & rational);
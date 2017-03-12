#include "stdafx.h"
#include "Rational.h"

CRational::CRational()
	: m_numerator(0)
	, m_denominator(1)
{}

CRational::CRational(int value)
	: m_numerator(value)
	, m_denominator(1)
{}

CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return double(m_numerator) / double(m_denominator);
}

std::pair<int, CRational> CRational::ToCompoundFraction() const
{
	int integerPart = m_numerator / m_denominator;
	int numerator = m_numerator - (integerPart * m_denominator);

	return std::pair<int, CRational>(integerPart, CRational(numerator, m_denominator));
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned CRational::GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

CRational CRational::operator+ () const
{
	return *this;
}

CRational CRational::operator- () const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const operator+ (CRational const &rational1, CRational const &rational2)
{
	return CRational((rational1.GetNumerator()*rational2.GetDenominator() + rational2.GetNumerator()*rational1.GetDenominator())
		, (rational1.GetDenominator()*rational2.GetDenominator()));
}

CRational const operator- (CRational const &rational1, CRational const &rational2)
{
	return CRational((rational1.GetNumerator()*rational2.GetDenominator() - rational2.GetNumerator()*rational1.GetDenominator())
		, (rational1.GetDenominator()*rational2.GetDenominator()));
}

// task 4 +=
CRational & CRational::operator +=(const CRational & rational2)
{
	*this = *this + rational2;
	Normalize();
	return *this;
}

// task 5 -=
CRational & CRational::operator -=(const CRational & rational2)
{
	*this = (*this - rational2);
	Normalize();
	return *this;
}


CRational const operator* (CRational const &rational1, CRational const &rational2)
{
	return CRational((rational1.GetNumerator() * rational2.GetNumerator()), (rational1.GetDenominator() * rational2.GetDenominator()));
}

CRational const operator/ (CRational const &rational1, CRational const &rational2)
{
	return CRational((rational1.GetNumerator() * rational2.GetDenominator()), (rational1.GetDenominator() * rational2.GetNumerator()));
}

// task 7 *=
CRational & CRational::operator *=(const CRational & rational2)
{
	*this = *this * rational2;
	Normalize();
	return *this;
}

// task 8 /=
CRational & CRational::operator /=(const CRational & rational2)
{
	*this = *this / rational2;
	Normalize();
	return *this;
}

// task 10 == and !=
bool const operator ==(const CRational & rational1, const CRational & rational2)
{
	return ((rational1.GetNumerator() == rational2.GetNumerator())
		&& (rational1.GetDenominator() == rational2.GetDenominator()));
}

bool const operator !=(const CRational & rational1, const CRational & rational2)
{
	return !(rational1 == rational2);
}

// task 11 <, <=, >, >=
bool const operator <(CRational const &rational1, CRational const &rational2)
{
	return (rational1.GetNumerator() * rational2.GetDenominator() < rational2.GetNumerator() * rational1.GetDenominator());
}

bool const operator >(CRational const &rational1, CRational const &rational2)
{
	return (rational1.GetNumerator() * rational2.GetDenominator() > rational2.GetNumerator() * rational1.GetDenominator());
}

bool const operator <=(CRational const &rational1, CRational const &rational2)
{
	return (rational1.GetNumerator() * rational2.GetDenominator() <= rational2.GetNumerator() * rational1.GetDenominator());
}

bool const operator >=(CRational const &rational1, CRational const &rational2)
{
	return (rational1.GetNumerator() * rational2.GetDenominator() >= rational2.GetNumerator() * rational1.GetDenominator());
}

// task 13 output
std::ostream & operator <<(std::ostream & strm, const CRational & rational)
{
	strm << rational.GetNumerator() << '/' << rational.GetDenominator();
	return strm;
}
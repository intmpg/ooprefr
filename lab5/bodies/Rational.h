#pragma once
#include "stdafx.h"

class CRational
{
public:
	// ������������ ������������ �����, ������ ���� (0/1)
	CRational();

	// ������������ ������������ �����, ������ value (value/1)
	CRational(int value);

	// ������������ ������������ �����, ������ numerator/denominator
	// ������������ ����� ������ ��������� � ��������������� ����:
	//	����������� ������������� (��������� ����� ���� �������������)
	//	��������� � ����������� �� ���������� ��������� (6/8 => 3/4 � �.�.)
	// ���� ����������� ����� ����, ������ ����������������� ������������ �����, ������ ����
	CRational(int numerator, int denominator);

	// �������������������
	int GetNumerator()const;

	// ���������� ����������� (����������� �����)
	int GetDenominator()const;

	// ���������� ��������� ��������� � ����������� � ���� ����� double
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
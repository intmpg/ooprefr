// FindMaxEx.cpp: определяет точку входа для консольного приложения.
//
	
#include "stdafx.h"
#include "FindMaxEx.h"
#include <string>
using namespace std;

void PrintExampleInput()
{
	std::cout << "input parameters of athlete (firstName middlename surname weight growth)" << std::endl;
	std::cout << "Vasya Andreev Pupkin 70 170" << std::endl;
}

void PrintInfoAboutAthlete(Athlete const & athlete)
{
	cout << "Name " << athlete.name << endl;
	cout << "Middle name " << athlete.middleName << endl;
	cout << "Surname " << athlete.surname << endl;
	cout << "Weight" << athlete.weight << endl;
	cout << "Growth " << athlete.growth << endl;;
}

int main()
{
	return 0;
}


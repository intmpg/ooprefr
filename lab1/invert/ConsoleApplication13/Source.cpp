#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>
#include <winsock.h>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <iomanip>

using namespace std;

void SearchDeterminant(double &determinant, double const matrix[3][3])
{
	double firstPartOfDeterminant = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[2][0] * matrix[0][1] * matrix[1][2] + matrix[1][0] * matrix[2][1] * matrix[0][2];
	double secondPartOfDeterminant = matrix[2][0] * matrix[1][1] * matrix[0][2] + matrix[0][0] * matrix[2][1] * matrix[1][2] + matrix[1][0] * matrix[0][1] * matrix[2][2];
	determinant = firstPartOfDeterminant - secondPartOfDeterminant;
}

void SearchMatrixOfCofactors(double const matrix[3][3], double cofactorsMatrix[3][3])
{
	cofactorsMatrix[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);
	cofactorsMatrix[0][1] = (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) * (-1);
	cofactorsMatrix[0][2] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
	cofactorsMatrix[1][0] = (matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]) * (-1);
	cofactorsMatrix[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]);
	cofactorsMatrix[1][2] = (matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]) * (-1);
	cofactorsMatrix[2][0] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]);
	cofactorsMatrix[2][1] = (matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0]) * (-1);
	cofactorsMatrix[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
}

void SearchTranspositionMatrix(double cofactorsMatrix[3][3])
{
	double storage;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = i; j < 3; ++j)
		{
			storage = cofactorsMatrix[i][j];
			cofactorsMatrix[i][j] = cofactorsMatrix[j][i];
			cofactorsMatrix[j][i] = storage;
		}
	}
}

void PrintMatrix(double const cofactorsMatrix[3][3], ofstream &outputFile)
{
	outputFile << "invert matrix:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			outputFile << std::fixed << std::setprecision(3) << cofactorsMatrix[i][j] << " ";
		}
		outputFile << endl;
	}
}

void MultipliedTranspositionMatrixOnDeterminant(double cofactorsMatrix[3][3], double const &determinant)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cofactorsMatrix[i][j] = cofactorsMatrix[i][j] * 1/determinant;
		}
	}
}

bool InvertMatrix(double const matrix[3][3], double cofactorsMatrix[3][3])
{
	double determinant;
	SearchDeterminant(determinant, matrix);
	if (determinant == 0)
	{
		return false;
	}
	else
	{
		SearchMatrixOfCofactors(matrix, cofactorsMatrix);
		SearchTranspositionMatrix(cofactorsMatrix);
		MultipliedTranspositionMatrixOnDeterminant(cofactorsMatrix, determinant);
		return true;
	}
}

bool ReadData(double matrix[3][3], ifstream &inputFile)
{
	if (inputFile.is_open())
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				inputFile >> matrix[i][j];
			}
		}
	}
	else
	{
		cout << "Failed to open input file for reading" << endl;
		return false;
	}
	return true;
}

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "");

	if (argc < 3)
	{
		printf("ERROR! Usage: invert.exe inputFile outputFile\n");
		return 1;
	}
	else 
		if (argc > 3)
		{
			printf("ERROR! Usage: invert.exe inputFile outputFile\n");
			return 1;
		}

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	double matrix[3][3];

	if (ReadData(matrix, inputFile))
	{
		double cofactorsMatrix[3][3];

		if (InvertMatrix(matrix, cofactorsMatrix))
			PrintMatrix(cofactorsMatrix, outputFile);	
		else 
			outputFile << "Matrix is singular and can't be inverted" << endl;
	}
	outputFile.flush();

	return 0;
}
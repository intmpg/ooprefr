#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>
#include <winsock.h>
#include <stdio.h>

using namespace std;

uint8_t FlipByte(uint8_t &byte)
{
	uint8_t	firstBit = 1;
	uint8_t lastBit = 128;
	uint8_t finalByte = 0;

	for (int i = 0; i < 8; i++)
	{
		if (byte & firstBit)
			finalByte |= lastBit;
		firstBit = firstBit << 1;
		lastBit = lastBit >> 1;
	}

	byte = finalByte;

	return byte;
}

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "");

	if (argc <= 2)
	{
		printf("ERROR! Usage: flipbyte.exe outputFile <inputByte> \n");
		return 1;
	}
	else if (argc > 3)
	{
		printf("ERROR! Usage: flipbyte.exe outputFile <inputByte> \n");
		return 1;
	}

	ofstream outputFile(argv[1]);
	int inputNumber = atoi(argv[2]);

	if (inputNumber > 0 && inputNumber < 256)
	{
		uint8_t byte = inputNumber;
		outputFile << int(FlipByte(byte));
	}
	else outputFile << "ERROR! Not correct number, number range 0-255";

	return 0;
}
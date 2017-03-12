// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "HttpUrl.h"
#include <iostream>

int main()
{
	std::string str;
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << ">";
		std::getline(std::cin, str);
		if (!std::cin.fail())
		{
			CHttpUrl CHttpUrl(str);
		}
	}
    return 0;
}


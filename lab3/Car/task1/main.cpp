// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "CarControl.h"

using namespace std;

int _tmain()
{

	CCar car;
	CCarControl carControl(car, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!carControl.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
	return 0;
}


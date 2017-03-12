// bodies.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Compound.h"
#include <map>
const std::string EXIT = "...";

int main()
{
	std::cout << "info about input compound bodies:" << std::endl;
	std::cout << "cone density radius height" << std::endl;
	std::cout << "cylinder density radius height" << std::endl;
	std::cout << "sphere density radius" << std::endl;
	std::cout << "parallelepiped density width height depth" << std::endl;
	std::string infoAboutBody;
	CCompound compound(infoAboutBody);
	while (infoAboutBody != EXIT)
	{
		std::getline(std::cin, infoAboutBody);
		if (infoAboutBody == EXIT) break;
		compound.GetInfoAboutBodies(infoAboutBody);
		compound.SaveNewMassAndVolume();

	}
	std::cout << "max mass = " << compound.GetMaxMass() << " " << compound.GetInfoAboutMaxMass() << std::endl;
	std::cout << "the most floating body: " << compound.GetInfoAboutTheMostFloatingBody() << std::endl;
	return 0;
}


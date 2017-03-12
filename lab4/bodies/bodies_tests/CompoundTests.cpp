#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../Compound.h"
#include <math.h>


struct Compound_
{
	std::string info;
	CCompound compound;
	Compound_()
		: compound(info)
	{}
	std::string infoAboutCone = "cone 123.2 13 4";
	double expectedDensity = 123.2;
	double expectedRadius = 13;
	double expectedHeight = 4;	
};
// Сфера
BOOST_FIXTURE_TEST_SUITE(Compound, Compound_)
	// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_cone)
	{
		BOOST_CHECK(static_cast<const CBody*>(&compound));
	}
	// имеет Высоту
	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		compound.GetInfoAboutBodies(infoAboutCone);
		compound.SaveNewMassAndVolume();
		BOOST_CHECK_EQUAL(compound.GetHeight(), expectedHeight);
	}

	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		compound.GetInfoAboutBodies(infoAboutCone);
		compound.SaveNewMassAndVolume();
		BOOST_CHECK_EQUAL(compound.GetDensity(), expectedDensity);
	}

	BOOST_AUTO_TEST_CASE(has_a_radius)
	{
		compound.GetInfoAboutBodies(infoAboutCone);
		compound.SaveNewMassAndVolume();
		BOOST_CHECK_EQUAL(compound.GetRadius(), expectedRadius);
	}

	struct Parall : Compound_
	{
			std::string infoAboutParall = "parallelepiped 123.2 13 4 3";
			double expectedDensity = 123.2;
			double expectedWidth = 13;
			double expectedHeight = 4;
			double expectedDepth = 3;	
			double expectedVolume = 156.0;
	};

	BOOST_FIXTURE_TEST_SUITE(CHECK_ANOTHER_PARAMETRS, Parall)
	// имеет ширину
		BOOST_AUTO_TEST_CASE(has_a_width)
		{
			compound.GetInfoAboutBodies(infoAboutParall);
			compound.SaveNewMassAndVolume();	
			BOOST_CHECK_EQUAL(compound.GetWidth(), expectedWidth);
		}
	// имеет глубину
		BOOST_AUTO_TEST_CASE(has_a_depth)
		{
			compound.GetInfoAboutBodies(infoAboutParall);
			compound.SaveNewMassAndVolume();
			BOOST_CHECK_EQUAL(compound.GetDepth(), expectedDepth);
		}
	
	// имеет объем
	/*	BOOST_AUTO_TEST_CASE(has_a_volume)
		{		
			compound.GetInfoAboutBodies(infoAboutCone);
			compound.SaveNewMassAndVolume();
			BOOST_CHECK_EQUAL(compound.GetCumutativeVolume(), expectedVolume);
		}
	// имеет массу
		BOOST_AUTO_TEST_CASE(has_a_mass)
		{
			compound.GetInfoAboutBodies(infoAboutCone);
			compound.SaveNewMassAndVolume();
			BOOST_CHECK_EQUAL(compound.GetCumutativeMass(), expectedVolume * expectedDensity);
		}
	// имеет строковое представление
/*	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(Parallelepiped:
	density = 8.8
	volume = 13248.312
	mass = 116585.1456
	width = 42.8
	height = 23.1
	depth = 13.4
)";
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).ToString(), expectedString);
	}*/
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
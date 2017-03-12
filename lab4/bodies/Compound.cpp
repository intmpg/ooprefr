#include "stdafx.h"
#include "Compound.h"

CCompound::CCompound(std::string info)
	: CBody("Compound", GetDensityOfCompoundBody())
{
}

void CCompound::GetInfoAboutBodies(std::string info)
{
	m_infoAboutBody = info;
}

void CCompound::CompareNewBodyMassWithMax(double mass)
{
	if (m_maxMass < mass)
	{
		m_maxMass = mass;
		m_infoAboutMaxMass = m_infoAboutBody;
	}
}

void CCompound::CompareNewBodyWithTheMostFloating(double density, double volume)
{
	double floatingOfBody = abs(density - DENSITYOFWATER) * G * volume;
	if (m_theMostFloating == 0)
	{
		m_theMostFloating = floatingOfBody;
		m_infoAboutMostFloating = m_infoAboutBody;
	}
	else
		if (floatingOfBody < m_theMostFloating)
		{
			m_theMostFloating = floatingOfBody;
			m_infoAboutMostFloating = m_infoAboutBody;
		}
}

std::string CCompound::GetInfoAboutTheMostFloatingBody()
{
	return m_infoAboutMostFloating;
}

std::string CCompound::GetInfoAboutMaxMass()
{
	return m_infoAboutMaxMass;
}

void CCompound::SaveNewMassAndVolume()
{
	std::istringstream strm(m_infoAboutBody);
	std::map <std::string, int> mapping;
	mapping["cone"] = 0;
	mapping["parallelepiped"] = 1;
	mapping["sphere"] = 2;
	mapping["cylinder"] = 3;
	mapping["compound"] = 4;
	std::string bodyType;
	strm >> bodyType;
	switch (mapping[bodyType])
	{
	case 0:
	{
		strm >> m_density;
		strm >> m_radius;
		strm >> m_height;
		CCone cone(m_density, m_radius, m_height);
		CompareNewBodyMassWithMax(cone.GetMass());
		CompareNewBodyWithTheMostFloating(m_density, cone.GetVolume());
		m_cumulativeMass += cone.GetMass();
		m_cumulativeVolume += cone.GetVolume();
		break;
	}
	case 1:
	{
		strm >> m_density;
		strm >> m_width;
		strm >> m_height;
		strm >> m_depth;
		CParallelepiped parall(m_density, m_width, m_height, m_depth);
		CompareNewBodyMassWithMax(parall.GetMass());
		CompareNewBodyWithTheMostFloating(m_density, parall.GetVolume());
		m_cumulativeMass += parall.GetMass();
		m_cumulativeVolume += parall.GetVolume();
		break;
	}
	case 2:
	{
		strm >> m_density;
		strm >> m_radius;
		CSphere sphere(m_density, m_radius);
		CompareNewBodyMassWithMax(sphere.GetMass());
		CompareNewBodyWithTheMostFloating(m_density, sphere.GetVolume());
		m_cumulativeMass += sphere.GetMass();
		m_cumulativeVolume += sphere.GetVolume();
		break;
	}
	case 3:
	{
		strm >> m_density;
		strm >> m_height;
		strm >> m_radius;
		CCylinder cylinder(m_density, m_radius, m_height);
		CompareNewBodyMassWithMax(cylinder.GetMass());
		CompareNewBodyWithTheMostFloating(m_density, cylinder.GetVolume());
		m_cumulativeMass += cylinder.GetMass();
		m_cumulativeVolume += cylinder.GetVolume();
		break;
	}
	}
}

double CCompound::GetMaxMass()const
{
	return m_maxMass;
}

double CCompound::GetDensityOfCompoundBody()
{
	return m_cumulativeMass / m_cumulativeVolume;
}

double CCompound::GetRadius()const
{
	return m_radius;
}

double CCompound::GetWidth()const
{
	return m_width;
}

double CCompound::GetHeight()const
{
	return m_height;
}

double CCompound::GetDensity()const
{
	return m_density;
}

double CCompound::GetDepth()const
{
	return m_depth;
}

double CCompound::GetVolume()const
{
	return m_cumulativeVolume;
}

double CCompound::GetCumulativeVolume()const
{
	return m_cumulativeVolume;
}

double CCompound::GetCumulativeMass()const
{
	return m_cumulativeMass;
}

void CCompound::AppendProperties(std::ostream & strm) const
{
	strm << "\twidth = " << GetWidth() << std::endl
		 << "\theight = " << GetHeight() << std::endl
		 << "\tdepth = " << GetDepth() << std::endl
		 << "\tradius = " << GetRadius() << std::endl;
}

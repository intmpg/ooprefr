#include "stdafx.h"
#include "Cylinder.h"

CCylinder::CCylinder(double density, double radius, double height)
	: CBody("Cylinder", density)
	, m_radiusOfBase(radius)
	, m_height(height)
{
}

double CCylinder::GetRadiusOfBase()const
{
	return m_radiusOfBase;
}

double CCylinder::GetHeight()const
{
	return m_height;
}

double CCylinder::GetVolume()const
{
	return (pow(m_radiusOfBase, 2) * M_PI) * m_height;
}

void CCylinder::AppendProperties(std::ostream & strm) const
{
	strm << "\tradius = " << GetRadiusOfBase() << std::endl
		 << "\theight = " << GetHeight() << std::endl;
}

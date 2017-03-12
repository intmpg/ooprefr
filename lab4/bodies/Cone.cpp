#include "stdafx.h"
#include "Cone.h"

CCone::CCone(double density, double radius, double height)
	: CBody("Cone", density)
	, m_radiusOfBase(radius)
	, m_height(height)
{
}

double CCone::GetRadiusOfBase()const
{
	return m_radiusOfBase;
}

double CCone::GetHeight()const
{
	return m_height;
}

double CCone::GetVolume()const
{
	return (pow(m_radiusOfBase, 2) * M_PI) * 1 / 3 * m_height;
}

void CCone::AppendProperties(std::ostream & strm) const
{
	strm << "\tradiusOfBase = " << GetRadiusOfBase() << std::endl
		 << "\theight = " << GetHeight() << std::endl;
}
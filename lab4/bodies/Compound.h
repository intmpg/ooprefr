#pragma once
#include "Body.h"
#include "Sphere.h"
#include "Parallelepiped.h"
#include "Cylinder.h"
#include "Cone.h"
#include <vector>
#include <map>
const int DENSITYOFWATER = 1000;
const double G = 9.8;
class CCompound final :
	public CBody
{
public:
	CCompound(std::string info);

	void GetInfoAboutBodies(std::string info);
	void SaveNewMassAndVolume();
	double GetDensityOfCompoundBody();
	double GetDensity()const;
	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	double GetMaxMass() const;
	double GetRadius()const;
	double GetCumulativeVolume() const;
	double GetCumulativeMass() const;
	double GetVolume() const override;
	void CompareNewBodyMassWithMax(double mass);
	void CompareNewBodyWithTheMostFloating(double density, double volume);
	std::string GetInfoAboutMaxMass();
	std::string GetInfoAboutTheMostFloatingBody();
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	std::vector<std::vector<int>> m_bodies;
	std::string m_infoAboutBody;
	std::string m_infoAboutMaxMass;
	std::string m_infoAboutMostFloating;
	std::string m_bodyType;
	double m_radius;
	double m_density;
	double m_width;
	double m_height;
	double m_depth;
	double m_cumulativeVolume;
	double m_cumulativeMass;
	double m_cumulativeDestiny;
	double m_maxMass;
	double m_theMostFloating;
	
};

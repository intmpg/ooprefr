#pragma once

struct Athlete
{
	std::string name;
	std::string surname;
	std::string middleName;
	double weight;
	double growth;
};

Athlete CreateAthlete(std::string const & str)
{
	std::istringstream strm(str);
	Athlete athlete;
	strm >> athlete.name;
	strm >> athlete.middleName;
	strm >> athlete.surname;
	strm >> athlete.weight;
	strm >> athlete.growth;
	return athlete;
}
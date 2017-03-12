#include "stdafx.h"
#include "../task01/FindMaxEx.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(FindMaxEx)

BOOST_AUTO_TEST_CASE(can_not_find_max_value_when_vector_is_empty)
{
	string maxValue;
	BOOST_CHECK(!FindMax(vector<string>(), maxValue, [](string const & first, string const &  second) {
		return first.length() < second.length(); }));
}

BOOST_AUTO_TEST_SUITE(can_find_athlete_when_)

BOOST_AUTO_TEST_CASE(vector_of_numbers_is_initialized)
{
	int maxValue = 0;
	vector<int> arr = { 5, 48, 230, 97, 23, 97, 2 };
	BOOST_CHECK(FindMax(arr, maxValue, [](int first, int second) {return first < second; }));
	BOOST_CHECK_EQUAL(maxValue, 230);
}

BOOST_AUTO_TEST_CASE(all_elements_are_equal)
{
	int maxValue;
	vector<int> arr = { 0, 0, 0, 0, 0, 0 };
	BOOST_CHECK(FindMax(arr, maxValue, [](int first, int second) {return first < second; }));
	BOOST_CHECK_EQUAL(maxValue, 0);
}

BOOST_AUTO_TEST_CASE(vector_of_numbers_is_initialized_without_lyamda_function)
{
	int maxValue = 0;
	vector<int> arr = { 5, 48, 230, 97, 23, 97, 2 };
	BOOST_CHECK(FindMax(arr, maxValue));
	BOOST_CHECK_EQUAL(maxValue, 230);
}

BOOST_AUTO_TEST_CASE(vector_contains_negative_numbers)
{
	int maxValue = 0;
	vector<int> arr = { 1, -2, 3, -10 };
	BOOST_CHECK(FindMax(arr, maxValue, [](int first, int second) {return first < second; }));
	BOOST_CHECK_EQUAL(maxValue, 3);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(can_find_max_length_in_vector_of_strings)
{
	string maxLenghtStr;
	vector<string> arr = { "parallelepiped", "min", "max", "some" };
	BOOST_CHECK(FindMax(arr, maxLenghtStr, [](string const & first, string const &  second) {
		return first.length() < second.length(); }));
	BOOST_CHECK_EQUAL(maxLenghtStr, "parallelepiped");
}

struct someAthletes
{
	vector<Athlete> athletes;
	someAthletes()
	{
		athletes =
		{
			CreateAthlete("Andrey Andreev A 50 100"),
			CreateAthlete("Timur Andreev B 70 120"),
			CreateAthlete("Vladimir Andreev C 40 140"),
			CreateAthlete("Nitita Andreev D 130 50"),
		};
	}
};

BOOST_FIXTURE_TEST_SUITE(can_find_athlete_, someAthletes)

	BOOST_AUTO_TEST_CASE(with_the_smallest_weigth)
	{
		Athlete athleteWithSmallestWeight;
		BOOST_CHECK(FindMax(athletes, athleteWithSmallestWeight, [](Athlete const & first, Athlete const & second) {
			return first.weight > second.weight;
		}));
		BOOST_CHECK_EQUAL(athleteWithSmallestWeight.name + athleteWithSmallestWeight.middleName + athleteWithSmallestWeight.surname, "VladimirAndreevC");
		BOOST_CHECK_EQUAL(athleteWithSmallestWeight.weight, 40);
		BOOST_CHECK_EQUAL(athleteWithSmallestWeight.growth, 140);
	}

	BOOST_AUTO_TEST_CASE(with_the_biggest_weigth_when_weigth_one_of_them_is_not_correct)
	{
		athletes.push_back(CreateAthlete("A B C a b"));
		Athlete athleteWithBiggesttWeight;
		BOOST_CHECK(FindMax(athletes, athleteWithBiggesttWeight, [](Athlete const & first, Athlete const & second) {
			return first.weight < second.weight;
		}));
		BOOST_CHECK_EQUAL(athleteWithBiggesttWeight.name + athleteWithBiggesttWeight.middleName + athleteWithBiggesttWeight.surname, "NititaAndreevD");
		BOOST_CHECK_EQUAL(athleteWithBiggesttWeight.weight, 130);
		BOOST_CHECK_EQUAL(athleteWithBiggesttWeight.growth, 50);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(can_replace_existing_max_value)
{
	float maxFloat = 555.f;
	vector<float> arr = { 54.3f, 548.f, -78.f, 98.f };
	BOOST_CHECK(FindMax(arr, maxFloat, [](float const & first, float const & second) {
		return first < second;
	}));
	BOOST_CHECK_EQUAL(maxFloat, 548.f);
}
BOOST_AUTO_TEST_SUITE_END()

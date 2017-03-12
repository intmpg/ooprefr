#include "stdafx.h"
#include "..\task1\Car.h"

using namespace std;

struct Car_
{
	CCar car;
	template <typename Op>
	void ExpectOperationSucceeds(Op && op, int expectedGear, int expectedSpeed, bool engineIsOn = true)
	{
		BOOST_CHECK(op()); // Ожидаем, что операция над car завершится успехом
						   // А потом сравниваем состояние с ожидаемым
		BOOST_CHECK_EQUAL(car.IsTurnedOn(), engineIsOn);
		BOOST_CHECK_EQUAL(car.GetGear(), expectedGear);
		BOOST_CHECK_EQUAL(car.GetSpeed(), expectedSpeed);
		BOOST_CHECK(car.GetMovement() == ((expectedSpeed > 0 && expectedGear != -1) ? MovementType::FORWARD: (expectedGear < 0 && expectedSpeed > 0) ? MovementType::BACK : MovementType::STAY));
	}
	template <typename Op>
	void ExpectOperationFails(Op && op)
	{
		const CCar clone(car);
		BOOST_CHECK(!op()); // выполняем действие, от которого ожидаем неуспешное завершение
							// Сравниваем состояние с клоном (к которому операция не применялась)
		BOOST_CHECK_EQUAL(car.IsTurnedOn(), clone.IsTurnedOn());
		BOOST_CHECK_EQUAL(car.GetGear(), clone.GetGear());
		BOOST_CHECK_EQUAL(car.GetSpeed(), clone.GetSpeed());
		BOOST_CHECK_EQUAL(car.GetMovement(), clone.GetMovement());
	}
};

BOOST_FIXTURE_TEST_SUITE(Check_engine, Car_)

	BOOST_AUTO_TEST_CASE(engine_is_off)
	{
		ExpectOperationFails([=] { return car.IsTurnedOn();});
	}

	BOOST_AUTO_TEST_CASE(cant_select_speed_when_engine_off)
	{
		ExpectOperationFails([=] { return car.SelectSpeed(1);});
	}

	BOOST_AUTO_TEST_CASE(cant_select_gear_when_engine_off)
	{
		ExpectOperationFails([=] { return car.SelectGear(1);});
	}

	BOOST_AUTO_TEST_CASE(engine_is_on)
	{
		ExpectOperationSucceeds([=] { return car.TurnOn();}, 0, 0);
	}

	struct WhenEngineOn : Car_
	{
		WhenEngineOn()
		{
			BOOST_CHECK(car.TurnOn());
		}
	};

	BOOST_FIXTURE_TEST_SUITE(START_CAR_SIMULATOR, WhenEngineOn)

		BOOST_AUTO_TEST_CASE(change_speed_and_gear_to_move_forward)
		{
			ExpectOperationSucceeds([=] { return car.SelectGear(1);}, 1, 0);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(10);}, 1, 10);
			ExpectOperationSucceeds([=] {return car.SetMovement(10, 1);}, 1, 10);
		}

		BOOST_AUTO_TEST_CASE(cant_switch_off_engine_when_moving_or_have_gear)
		{
			ExpectOperationSucceeds([=] { return car.SelectGear(1);}, 1, 0);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(10);}, 1, 10);
			ExpectOperationSucceeds([=] {return car.SetMovement(10, 1);}, 1, 10);
			ExpectOperationFails([=] { return car.TurnOff();});
		}

		BOOST_AUTO_TEST_CASE(try_to_change_speed_and_gear_in_out_of_max_interval)
		{
			ExpectOperationSucceeds([=] { return car.SelectGear(1);}, 1, 0);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(30);}, 1, 30);
			ExpectOperationFails([=] { return car.SelectGear(4);});
			ExpectOperationFails([=] { return car.SelectSpeed(31);});
			ExpectOperationSucceeds([=] { return car.SelectGear(3);}, 3, 30);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(60);}, 3, 60);
			ExpectOperationSucceeds([=] { return car.SelectGear(5);}, 5, 60);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(150);}, 5, 150);
			ExpectOperationFails([=] { return car.SelectGear(6);});
			ExpectOperationFails([=] { return car.SelectSpeed(200);});
			ExpectOperationSucceeds([=] {return car.SetMovement(150, 5);}, 5, 150);
		}

		BOOST_AUTO_TEST_CASE(try_to_move_back)
		{

			ExpectOperationSucceeds([=] { return car.SelectGear(-1);}, -1, 0);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(15);}, -1, 15);
			ExpectOperationFails([=] { return car.SelectSpeed(21);});
			ExpectOperationSucceeds([=] {return car.SetMovement(15, -1);}, -1, 15);
		}

		BOOST_AUTO_TEST_CASE(cant_change_gear_to_reverse_when_speed_more_zero)
		{
			ExpectOperationSucceeds([=] { return car.SelectGear(1);}, 1, 0);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(10);}, 1, 10);
			ExpectOperationFails([=] { return car.SelectGear(-1);});	
			ExpectOperationSucceeds([=] {return car.SetMovement(10, 1);}, 1, 10);
		}

		BOOST_AUTO_TEST_CASE(cant_change_gear_from_reverse_to_first_when_speed_more_zero)
		{
			ExpectOperationSucceeds([=] { return car.SelectGear(-1);}, -1, 0);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(15);}, -1, 15);
			ExpectOperationFails([=] { return car.SelectGear(1);});
			ExpectOperationSucceeds([=] {return car.SetMovement(15, -1);}, -1, 15);
		}

		BOOST_AUTO_TEST_CASE(cant_change_gear_from_neutral_when_move_back_to_first_gear)
		{
			ExpectOperationSucceeds([=] { return car.SelectGear(-1);}, -1, 0);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(15);}, -1, 15);
			BOOST_CHECK(car.SelectGear(0));
			ExpectOperationFails([=] { return car.SelectGear(1);});
			BOOST_CHECK(car.GetMovement() == BACK);			
		}

		BOOST_AUTO_TEST_CASE(can_lose_speed_when_neutral_gear)
		{
			ExpectOperationSucceeds([=] { return car.SelectGear(1);}, 1, 0);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(30);}, 1, 30);
			ExpectOperationSucceeds([=] { return car.SelectGear(0);}, 0, 30);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(29);}, 0, 29);
			ExpectOperationFails([=] { return car.SelectSpeed(30);});
			ExpectOperationSucceeds([=] { return car.SelectSpeed(25);}, 0, 25);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(0);}, 0, 0);
		}

		BOOST_AUTO_TEST_CASE(try_to_simulate_a_ride)
		{
			ExpectOperationSucceeds([=] { return car.SelectGear(-1);}, -1, 0);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(20);}, -1, 20);
			ExpectOperationFails([=] { return car.SelectSpeed(21);});
			ExpectOperationSucceeds([=] { return car.SelectSpeed(0);}, -1, 0);
			ExpectOperationSucceeds([=] { return car.SelectGear(0);}, 0, 0);
			ExpectOperationSucceeds([=] { return car.SelectGear(1);}, 1, 0);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(30);}, 1, 30);
			ExpectOperationFails([=] { return car.SelectSpeed(31);});
			ExpectOperationFails([=] { return car.SelectGear(5);});
			ExpectOperationSucceeds([=] { return car.SelectGear(3);}, 3, 30);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(60);}, 3, 60);
			ExpectOperationFails([=] { return car.SelectSpeed(61);});
			ExpectOperationFails([=] { return car.SelectSpeed(29);});
			ExpectOperationFails([=] { return car.SelectGear(1);});
			ExpectOperationSucceeds([=] { return car.SelectSpeed(30);}, 3, 30);
			ExpectOperationSucceeds([=] { return car.SelectGear(0);}, 0, 30);
			ExpectOperationSucceeds([=] { return car.SelectSpeed(0);}, 0, 0);
			ExpectOperationFails([=] { return car.SelectSpeed(1);});
			ExpectOperationSucceeds([=] {return car.SetMovement(0, 0);}, 0, 0);
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


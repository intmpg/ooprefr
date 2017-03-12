#pragma once
#pragma warning(disable:4592)
#include "stdafx.h"

enum MovementType
{
	STAY,
	BACK,
	FORWARD
};

class CCar
{
public:
	bool IsTurnedOn()const;
	bool TurnOn();
	bool TurnOff();
	int GetGear()const;
	bool SelectGear(int gear);
	int GetSpeed()const;
	bool SelectSpeed(int speed);
	MovementType GetMovement()const;
	bool SetMovement(int const & speed, int const & gear);

private:
	bool m_isOn = false;
	int m_currentGear = 0;
	int m_currentSpeed = 0;

	MovementType m_movement = STAY;
};
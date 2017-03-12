#pragma once
#pragma warning(disable:4100)
#include "Car.h"

class CCarControl : boost::noncopyable
{
public:
	CCarControl(CCar & m_car, std::istream & input, std::ostream & output);
	bool HandleCommand();
	
private: 
	bool TurnOnEngine(std::istream & args);
	bool TurnOffEngine(std::istream & args);
	bool SetGear(std::istream & args);
	bool SetSpeed(std::istream & args);
	bool GetInfo(std::istream & input)const;

private:
	typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

	int m_newSpeed;
	int m_newGear;

	CCar m_car;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;

};

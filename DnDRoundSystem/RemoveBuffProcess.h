#pragma once
#include <string>
#include "UnitList.h"
#include "Unit.h"
#include <iostream>
class RemoveBuffProcess
{
private:
	string cmd; //konsol input
	Unit* unit; //jeg skal ikke bruge en ny unit, jeg skal bare bruge en pointer
	bool approved = false; //checker om klassen skal fortsætte
	string name;
public:
	void Process(Unit *unit);
};


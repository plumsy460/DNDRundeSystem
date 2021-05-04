#pragma once
#include <string>
#include "Unit.h"
#include "UnitList.h"
#include <iostream>
using namespace std;
class ModifyHP
{
private:
	string cmd; //konsol input
	bool approved = false; //checker om klassen skal fortsætte
	int hp = 0;
public:
	void ChangeHP(Unit *unit);
};


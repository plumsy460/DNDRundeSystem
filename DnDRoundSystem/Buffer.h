#pragma once
#include <string>
#include "UnitList.h"
#include "Unit.h"
#include <iostream>
using namespace std;

class Buffer //bliver brugt til at tilf�je Effect til Unit
{
private:
	string cmd; //konsol input
	bool approved = false; //checker om klassen skal forts�tte
	string name;
	int duration = 0;
public:
	void Process(Unit *unit);
};


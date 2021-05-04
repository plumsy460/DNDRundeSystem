#pragma once
#include <string>
#include "UnitList.h"
#include "Unit.h"
#include <iostream>
using namespace std;

class Buffer //bliver brugt til at tilføje Effect til Unit
{
private:
	string cmd; //konsol input
	bool approved = false; //checker om klassen skal fortsætte
	string name;
	int duration = 0;
public:
	void Process(Unit *unit);
};


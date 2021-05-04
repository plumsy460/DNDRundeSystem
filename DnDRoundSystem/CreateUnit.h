#pragma once
#include <string>
#include <iostream>
#include "UnitList.h"
using namespace std;

class CreateUnit
{
private:
	string cmd; //konsol input
	bool approved = false; //checker om klassen skal forts�tte
	string name; //navnet p� ny unit
	int initiative = 0;
	int hp = 0;
public:
	void NewUnit(UnitList* ul);
};


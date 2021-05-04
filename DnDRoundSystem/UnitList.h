#pragma once
#include "Unit.h"
#include "Player.h"
#include "ColorText.h"

#include <iostream>
#include <algorithm>

using namespace std;
class UnitList
{
private:
	ColorText colorText; //bruges til at farme text
	
public:
	UnitList();
	~UnitList();

	Unit** units = new Unit*[0]; //2 stjerner er en pointer til en array af pointers
	int count = 0;

	void AddUnit(int init, string name, int hp, bool isPlayer);
	void RemoveUnit(string name);
	void Sort();
	void Print();
};


#pragma once
#include "Unit.h"
class Player : public Unit
{
public:
	Player(int init, string name, int hp, bool isPlayer);
	~Player();
	void PrintMe();
};


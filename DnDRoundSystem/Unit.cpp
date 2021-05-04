#include "Unit.h"


Unit::Unit()
{
	this->init = 0;
	this->name = "";
	effectList = new EffectList();
}

Unit::~Unit()
{
	delete effectList; //dette kalder en metode som sletter alle effekter i arrayet
	nullptr;
}

Unit::Unit(int init, string name, int hp, bool isPlayer)
{
	this->init = init;
	this->name = name;
	this->hp = hp;
	effectList = new EffectList();
}

void Unit::AddEffect(string name, int duration)
{
	effectList->AddEffect(name, duration);
}

void Unit::PrintMe()
{
	cout << name;
}



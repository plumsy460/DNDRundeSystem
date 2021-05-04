#include "Player.h"

Player::Player(int init, string name, int hp, bool isPlayer)
{
	this->init = init;
	this->name = name;
	this->hp = hp;
	effectList = new EffectList();
}

Player::~Player()
{
	//delete effectList; //dette kalder en metode som sletter alle effekter i arrayet
}

void Player::PrintMe()//overrider print metoden s� der kommer farve p�
{
	colorText.ApplyColor(name, 11);
}

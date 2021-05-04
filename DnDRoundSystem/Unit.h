#pragma once
#include "EffectList.h"
#include <string>
#include <iostream>
#include "ColorText.h"
using namespace std;

class Unit
{
private:
	
	

public:
	string name;
	int hp;
	int init;
	EffectList *effectList;
	Unit();
	~Unit();
	Unit(int init, string name, int hp, bool isPlayer);
	void AddEffect(string name, int duration);
	virtual void PrintMe();//når en klasse har en virtual metode, så kan man bruge Dynamic Cast
	//-fordi nu er klassen polymoprhic
	
protected:
	ColorText colorText; //bruges til at farme text
	
};


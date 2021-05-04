#pragma once
#include "Effect.h"
using namespace std; //edited
class EffectList
{
private:


public:
	EffectList();
	~EffectList();

	Effect** effects = new Effect*[0];//2 stjerner er en pointer til en array af pointers
	int count = 0;

	void AddEffect(string name, int duration);
	void RemoveEffect(int index);
	void Sort();//bliver ikke brugt
};

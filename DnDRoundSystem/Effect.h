#pragma once
#include <string>
using namespace std;
class Effect
{
public:
	string buffName = " ";
	int duration = 0;
	Effect();
	~Effect();
	Effect(string buffName, int duration);
};


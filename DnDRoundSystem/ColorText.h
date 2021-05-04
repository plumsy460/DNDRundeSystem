#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h> 
using namespace std;
class ColorText
{
private:
	int i = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);;
public:
	void ApplyColor(string txt, int color);
};


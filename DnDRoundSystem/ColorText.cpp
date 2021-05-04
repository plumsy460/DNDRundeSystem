#include "ColorText.h"

void ColorText::ApplyColor(string txt, int color)
{
    SetConsoleTextAttribute(hConsole, color);
    std::cout << txt; //udskriver text efter det blevet farve
    SetConsoleTextAttribute(hConsole, 15);//resetter tilbage til hvid farve
}

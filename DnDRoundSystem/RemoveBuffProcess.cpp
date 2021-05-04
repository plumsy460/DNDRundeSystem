#include "RemoveBuffProcess.h"

void RemoveBuffProcess::Process(Unit * unit)
{
		cout << "What is the name of the buff? (cap sensitive)\n";
		cin >> cmd;
		for (int i = 0; i < unit->effectList->count; i++)//checker om navnet eksiterer på effect listen
		{
			if (unit->effectList->effects[i]->buffName == cmd)
			{
				unit->effectList->RemoveEffect(i);
			}
		}
}

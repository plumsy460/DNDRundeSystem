#include "NewRound.h"


void NewRound::NextRound(UnitList ul)
{

	for (int i = 0; i < ul.count; i++)//gennemg�r alle units
	{
		for (int e = 0; e < ul.units[i]->effectList->count; e++)//checker hvilke effects der har duration 0
		{
			ul.units[i]->effectList->effects[e]->duration--; //gr�nne streger fordi jeg bruger e-- l�ngere nede
			if (ul.units[i]->effectList->effects[e]->duration < 0)//hvis duration expired aka == 0
			{
				delete ul.units[i]->effectList->effects[e];//fjerner bestemte effect
				ul.units[i]->effectList->effects[e] = nullptr;//fjerner pointer
				ul.units[i]->effectList->RemoveEffect(e);//fjerner element i listen, dette reducerer mit loop med 1 fordi count--
				e--; //derfor skal jeg et skridt tilbage i arrayet, fordi jeg har reduceret effectList array med 1
				// e-- er n�dvendig, hvis flere effekter p� samme unit udl�ber samtidig
			}
		}
	}

}

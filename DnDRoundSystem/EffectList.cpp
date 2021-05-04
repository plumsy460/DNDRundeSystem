#include "EffectList.h"
#include "Effect.h"
#include <iostream>
#include <algorithm>
using namespace std;

EffectList::EffectList()
{

}

EffectList::~EffectList() //bliver kaldt n�r en unit fjernes
{
	for (int i = 0; i < count; i++)
	{
		delete effects[i];
		effects[i] = nullptr;
	}
	delete effects;
	effects = nullptr;
}

void EffectList::AddEffect(string name, int duration)//g�r mit array 1 st�rre
{
	(count)++;

	Effect** tmpArray = new Effect*[count];//laver et array der er 1 st�rre
	for (int i = 0; i < count - 1; i++)
	{
		tmpArray[i] = effects[i];//kopierer alle elementer over i den nye array
	}

	delete[] effects;//fjerner de gamle array pointers
	effects = tmpArray;//s�tter min "liste" til at v�re den nye array
	tmpArray = nullptr;//fjerner dens pointer

	effects[count - 1] = new Effect(name, duration);//inds�tter effect (jeg skriver -1 for at tage h�jde for 0 index)
}

void EffectList::RemoveEffect(int index) //denne metode g�r min array 1 mindre og fjerne en effect
{
	bool checkRemoved = false;
	
	Effect** tmpArray = new Effect * [count -1];//laver en ny array af pointers.
			//jeg skriver -1 fordi min nye array er 1 kortere
	for (int i = 0; i < count; i++)
	{
		if (i == index && !checkRemoved)
		{
			checkRemoved = true;//checker at jeg har ramt den effect som skal fjernes
			continue;//resten af det nuv�rende loop bliver sprunget over
		}
		if (checkRemoved == false) 	
		{ 
			tmpArray[i] = effects[i]; //hvis jeg ikke er n�et til den index som skal fjernes
					//-kan jeg kopierer over fra samme index
		}
		else
		{
			tmpArray[i-1] = effects[i];//jeg skriver -1 fordi jeg skal undg� den effect
					//-som skal fjernes fra det nye array
		}
	}
	(count)--;
	delete effects[index]; //fjerner gamle array
	effects[index] = nullptr;

	delete[] effects;
	effects = tmpArray; //bruger den nye array
	tmpArray = nullptr;
}

void EffectList::Sort()//bruges ikke
{
	//sort(effects, effects + count, [](Effect const& a, Effect const& b) -> bool
	//{ return a.duration > b.duration; });
}

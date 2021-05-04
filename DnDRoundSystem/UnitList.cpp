#include "UnitList.h"

UnitList:: UnitList()
{

}
UnitList:: ~UnitList()
{
}
void UnitList::AddUnit(int init, string name, int hp, bool isPlayer)//tilføjer ny unit
{
	count++;

	Unit** tmpArray = new Unit*[count];//laver en ny array der er 1 større
	for (int i = 0; i < count - 1; i++)
	{
		tmpArray[i] = units[i];//kopierer alle elementer over i den nye array
	}

	delete[] units;//sletter gamle array
	units = tmpArray; //sætter min "liste" til at være den nye array
	tmpArray = nullptr; //fjerner pointer

	if (isPlayer == true)
	{
		units[count - 1] = new Player(init, name, hp, isPlayer);//laver ny Player. Jeg skriver -1 for at tage højde for index 0
	}
	else 
	{
		units[count - 1] = new Unit(init, name, hp, isPlayer);//laver ny unit. Jeg skriver -1 for at tage højde for index 0
	}
	
}

void UnitList::RemoveUnit(string removeName)//denne metode fjerner alle units med et angivet navn. Idealt set bør man aldrig give en unit det samme navn
{
	for (int unitIndex = 0; unitIndex < count; unitIndex++)
	{
		if (units[unitIndex]->name == removeName)
		{
			bool checkRemoved = false;
			Unit** tmpArray = new Unit * [count -1];//laver en ny array af pointers.
			//jeg skriver -1 fordi min nye array er 1 kortere
			for (int unit = 0; unit < count; unit++)
			{
				if (unit == unitIndex && !checkRemoved)
				{
					checkRemoved = true;//checker at jeg har ramt den unit som skal fjernes
					continue; //dette gør at resten af det nuværende loop bliver sprunget over
				}

				if (checkRemoved == false)
				{
					tmpArray[unit] = units[unit];//hvis jeg ikke er nået til den index som skal fjernes
					//-kan jeg kopierer over fra samme index
				}
				else
				{
					tmpArray[unit - 1] = units[unit];//jeg skriver -1 fordi jeg skal undgå den unit
					//-som skal fjernes fra det nye array
				}
			}

			//if (dynamic_cast<Player*>(units[unitIndex]))
			//{
			//	delete dynamic_cast<Player*>(units[unitIndex]);//sletter den specificeret unit
			//	units[unitIndex] = nullptr;
			//}

			(count)--;
			delete units[unitIndex];//sletter den specificeret unit
			//units[unitIndex] = nullptr;//sletter også dens pointer

			delete[] units;//sletter den gamle pointer array
			units = tmpArray; //sætter mit array til at være den nye
			tmpArray = nullptr;//fjerner pointer
			
			break;
		}
	}
}

void UnitList::Sort()//sorterer efter initiativ (init)
{
	sort(units, units + count, [](Unit const * a, Unit const * b) -> bool
	{ return a->init > b->init; } );
}

void UnitList::Print()//spaghetti kode. Det er her jeg printer listen ud til konsollen
{
	colorText.ApplyColor("Init    Names    HP     Effects\n", 9);
	//3 & 9 = blue
	//4 & 12 = red
	//11 = teal
	//14 yellow
	Sort();
	for (int i = 0; i < count; i++) //count er størrelsen på min UnitList array
	{
		if (units[i]->init < 10) //hvis initiativ er mindre end 10, så rykker den tallet 1 frem så det ser pænere ud
		{
			cout << " ";
		}
		cout << units[i]->init; //udskriver initiativ på unit
		cout << "  ";
		int tmp = 10 - units[i]->name.size(); //jeg sørger for der er en bestemt afstand mellem initiativ og navn
		for (int i = 0; i < tmp; i++) //skaber mellemrum for hvert char hvis navnet er mindre end 10 chars
		{
			cout << " ";
		}

		units[i]->PrintMe();

		cout << "   ";
		cout << units[i]->hp; //udskriver hp
		
		if (units[i]->hp < 10) //skaber afstand alt efter hvor mange cifre hp er
		{
			cout << "  ";
		}
		else if (units[i]->hp < 100) //skaber pænere afstand mellem HP og effekter
		{
			cout << " ";
		}

		if (units[i]->effectList->count == 0)//checker hvor mange effecter en unit har i sin efffectList
		{
			//skriver ikke noget ud hvis unit har ingen effects
		}
		else
		{
			for (int e = 0; e < units[i]->effectList->count; e++) //udskriver hver effect
			{
				cout << " -> ";
				if (units[i]->effectList->effects[e]->duration == 0) //checker om effect er udløbet
				{
					colorText.ApplyColor(units[i]->effectList->effects[e]->buffName, 14);//tydeliggøre med en farve
					colorText.ApplyColor(" has expired!", 14);
				}
				else
				{
					cout << units[i]->effectList->effects[e]->buffName; //viser effect navn
					cout << " ";
					cout << units[i]->effectList->effects[e]->duration;//viser effect tid
				}
				
			}
		}
		cout << "\n";
	}
}
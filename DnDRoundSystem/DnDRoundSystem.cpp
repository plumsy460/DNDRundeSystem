#include <iostream>
#include "UnitList.h"
#include "Buffer.h"
#include "NewRound.h"
#include "CreateUnit.h"
#include "modifyHP.h"
#include "RemoveBuffProcess.h"
#include "Unit.h"
#include "ColorText.h"
#include <stdlib.h>
using namespace std;

int main()
{
	// -- INTRO --
	//dette system er lavet til at overblik for en Dungeon Master i Dungeons and Dragons.
	//Systemet holder styr på cooldowns, buff durations og andre effekter, og giver brugeren overblik over
	//hvornår en effekt er udløbet

	//brugeren kan selv tilføje effekter til units ved at skrive "b". Fx hvis en spiller kaster en ability med cooldown,
	//så kan Dungeon Master indskrive en "effect" på spilleren og kalde den fx "FireballCooldown" og give den en duration, fx "3".

	//brugeren kan skrive "r" for at starte ny runde, og vil se at nu er FireballCooldown sat til 2.
	//Når FireballCooldown er sat til 0 viser konsollen tydeligt at nu er FireballCooldown "Expired"
	//så kan dungeon master fortælle spilleren, at nu er fireball klar igen.
	
	//Når systemet startes er der en brugervejledning til de forskellige funktioner

	Unit* unit;
	Buffer buffer;
	NewRound newRound;
	CreateUnit createUnit;
	UnitList ul; 
	ModifyHP modifyHP;
	RemoveBuffProcess removeBuffProcess;
	ColorText colorText;
	bool approved = false;
#pragma region STRESS TEST
	//Her checker jeg efter leaks. Jeg tilføjer en ny unit, giver den en buff, og fjerner uniten i et while loop
//while (true)
//{
//	ul.AddUnit(6, "Ana", 10, false);
//	ul.units[0]->AddEffect("buff", 3);
//	ul.RemoveUnit("Ana");
//}
#pragma endregion

	//jeg instantierer 6 tilfældelige Units.
	//herunder er 3 spillere
	ul.AddUnit(10, "Joanie", 124, true); //initativ, navn, hp, player
	ul.AddUnit(15, "Sanook", 10, true);
	ul.AddUnit(6, "Ana", 10, true);
	//herunder er 3 npc'er
	ul.AddUnit(4, "Skeleton", 3, false);
	ul.AddUnit(7, "Zombie", 10, false);
	ul.AddUnit(3, "Ghoul", 9, false);
	
	unit = ul.units[0];//så koden ikke brokker sig over uinitialized local pointer
	string cmd;//bruger jeg til at aflæse console commands

	while (true)
	{
		approved = false;
		ul.Print();//udskriver listen
		colorText.ApplyColor("\nUser guide:", 14);
		cout << "\n- Type the name of the unit you wish to modify\n- Type'u' to create new unit\n- Type 'r' to start new round\n\n";
		
		cin >> cmd; //venter på console input
		if (cmd == "u") 
		{
			createUnit.NewUnit(&ul);//skaber ny unit
		}
		else if (cmd == "r") 
		{
			newRound.NextRound(ul);//starter ny runde
		}
		else 
		{
			for (int i = 0; i < ul.count; i++) //checker om navnet eksiterer på unit listen
			{
				if (ul.units[i]->name == cmd)
				{
					unit = (ul.units[i]);
					approved = true;
				}
			}
		}

		//Herunder ses oversigtslisten af unit modify console commands
		if (approved == true)
		{
			colorText.ApplyColor("What do you wish to modify with this unit?", 14);
			cout << "\n'b' = add effect to unit\n'ru' = remove unit\n'h' = modify hp of unit\n'rb' remove specific effect from unit\n\n";
			cin >> cmd; //venter på console input
			if (cmd == "b") //tilføjer effect/buff på unit
			{
				buffer.Process(unit);
			}
			if (cmd == "ru") //fjerner unit via navn
			{
				ul.RemoveUnit(unit->name);
			}
			if (cmd == "h")//ændrer hp
			{
				modifyHP.ChangeHP(unit);
			}
			if (cmd == "rb")//fjerner buff
			{
				removeBuffProcess.Process(unit);
			}
		}
		
		getchar();
		system("CLS"); //clear console (virker i release)
		//cout << "\x1B[2J\x1B[H"; //clear console
	}

	return 0;
}

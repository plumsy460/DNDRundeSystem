#include "ModifyHP.h"

void ModifyHP::ChangeHP(Unit *unit)
{
		approved = true;
		cout << "How much hp do you want to add? (type -x for subtracting)\n"; //hvor hp skal ændres
		cin >> cmd;
		try //try catch er relativt tungt
		{
			hp = stoi(cmd); //forsøger at lave console input til int
		}
		catch (...)
		{
			cout << "Failed to convert to integer";
			approved = false;
		}
		if (approved)
		{
			unit->hp += hp; //laver hp om på unit. Virker også hvis man har skrevet fx -10
		}
}

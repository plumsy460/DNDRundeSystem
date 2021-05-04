#include "CreateUnit.h"
//using namespace std;

void CreateUnit::NewUnit(UnitList* ul)
{
	
	cout << "What is the name of the new unit?\n";
	cin >> name;
	cout << "What is it's initative?\n";
	cin >> cmd;
	approved = true;
	try //try catch er relativt tungt
	{
		initiative = stoi(cmd);
	}
	catch (...)
	{
		cout << "Failed to convert to integer";
		approved = false;
	}
	if (approved)
	{
		cout << "What is it's HP?\n";
		cin >> cmd;
		try //try catch er relativt tungt
		{
			hp = stoi(cmd);
		}
		catch (...)
		{
			cout << "Failed to convert to integer";
			approved = false;
		}
		if (approved)
		{
			cout << "Is the new unit a Player? type 'yes' if true\n";
			cin >> cmd;
			if (cmd == "yes")
			{
				ul->AddUnit(initiative, name, hp, true);//laver ny Player
			}
			else
			{
				ul->AddUnit(initiative, name, hp, false); //laver ny NPC
			}
			
		}
	}

}

#include "Buffer.h"
//using namespace std;


void Buffer::Process(Unit* unit)
{
		approved = true;

		cout << "What is the name of the effect? (no spaces allowed)\n"; //navngiver effekten
		cin >> cmd;
		name = cmd;
		cout << "What is the duration of the effect?\n"; //angiver duration
		cin >> cmd;
		try //try catch er relativt tungt
		{
			duration = stoi(cmd);
		}
		catch (...)
		{
			cout << "Failed to convert to integer";
			approved = false;
		}
		if (approved)
		{
			unit->AddEffect(name, duration);
		}

}
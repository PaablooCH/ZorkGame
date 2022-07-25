#include "npc.h"

Npc::Npc(string name, string description, int maxHealth, int attack, EntityType type, CreatureType creatureType) :
	Creature(name, description, maxHealth, attack, type, creatureType)
{
}

void Npc::Talk()
{
	if (dialog.size() > 1) {
		string talk = dialog.back();
		dialog.pop_back();
		cout << name << ": " << talk << endl;
	}
	else {
		string talk = dialog.back();
		cout << name << ": " << talk << endl;
	}
}

void Npc::addDialog(string dialog)
{
	this->dialog.push_back(dialog);
}

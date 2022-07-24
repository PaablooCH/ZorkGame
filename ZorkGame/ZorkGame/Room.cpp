#include "Room.h"

Room::Room(string name, string description) :
	Entity(name, description)
{
}

void Room::Examine()
{
	if (contains.size() == 0) {
		cout << "The room is empty." << endl;
		return;
	}
	cout << "This room contains:" << endl;
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++) {
		cout << "	" << (*it)->GetName() << endl;
	}

}

bool Room::Examine(const string& object)
{
	Item* item = FindItem(object);
	if (item != nullptr) {
		cout << item->GetName() << " " << item->GetDescription() << endl;
		if (item->GetType() == CREATURE) {
			Creature* creature = ((Creature*) item);
			cout << "  Health: " << creature->GetHealth() << endl;
			cout << "  Attack: " << creature->GetAttack() << endl;
		}
		return true;
	}
	return false;
}

void Room::Look(const string& direction)
{
	Exit* exit = FindExit(direction);
	if (exit != nullptr) {
		exit->ExistExit(this, direction);
	}
	
}

Exit* Room::FindExit(const string& direction)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++) {
		if ((*it)->GetType() == EXIT) {
			Exit* exit = (Exit*) *it;
		}
	}
	return nullptr;
}

Room* Room::Move(const string& direction)
{
	Exit* exit = FindExit(direction);
	if (exit != nullptr) {
		return exit->MoveNextRoom(this);
	}
	return nullptr;
}

Item* Room::Take(const string& object)
{
	Item* item = FindItem(object);
	if (item != nullptr) {
		contains.remove(item);
	}
	return item;
}

Item* Room::Loot(const string& target)
{
	Creature* creature = FindCreature(target);
	if (creature != nullptr) {
		return creature->Loot();
	}
	return nullptr;
}

void Room::Attack(const string& target, const int& damage)
{
	Creature* creature = FindCreature(target);
	if (creature != nullptr) {
		creature->Damaged(damage);
	}
}

Item* Room::FindItem(const string& object)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++) {
		if ((*it)->GetType() == ITEM && (*it)->GetName() == object) {
			return (Item*)*it;
		}
	}
	return nullptr;
}

Creature* Room::FindCreature(const string& target)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++) {
		if ((*it)->GetType() == CREATURE && (*it)->GetName() == target) {
			return (Creature*)(*it);
		}
	}
	cout << target << " is not in this room." << endl;
	return nullptr;
}

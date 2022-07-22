#include "Room.h"

Room::Room() :
	Entity(name, description)
{
	this->name = name;
	this->description = description;
}

void Room::Examine()
{
	if (contains.size() == 0) {
		cout << "The room is empty." << endl;
		return;
	}
	cout << "This room contains:" << endl;
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++) {
		cout << "	" << (*it)->name << endl;
	}

}

void Room::Look(string direction)
{
	Exit* exit = FindExit(direction);
	if (exit != nullptr) {
		exit->ExistExit(this, direction);
	}
	
}

Exit* Room::FindExit(string direction)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++) {
		if ((*it)->type == EXIT) {
			Exit* exit = (Exit*) *it;
		}
	}
	return nullptr;
}

Room* Room::Move(string direction)
{
	Exit* exit = FindExit(direction);
	if (exit != nullptr) {
		return exit->MoveNextRoom(this);
	}
	return nullptr;
}

Item* Room::Take(string object)
{
	Item* item = FindItem(object);
	if (item != nullptr) {
		contains.remove(item);
	}
	return item;
}

Item* Room::Loot(string target)
{
	Creature* creature = FindCreature(target);
	if (creature != nullptr) {
		return creature->Loot();
	}
	return nullptr;
}

void Room::Attack(string target, int damage)
{
	Creature* creature = FindCreature(target);
	if (creature != nullptr) {
		creature->GetHit(damage);
	}
}

Item* Room::FindItem(string object)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++) {
		if ((*it)->type == ITEM && (*it)->name == object) {
			return (Item*)*it;
		}
	}
	return nullptr;
}

Creature* Room::FindCreature(string target)
{
	for (list<Entity*>::iterator it = contains.begin(); it != contains.end(); it++) {
		if ((*it)->type == CREATURE && (*it)->name == target) {
			return (Creature*)(*it);
		}
	}
	cout << target << " is not in this room." << endl;
	return nullptr;
}

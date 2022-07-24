#pragma once
#include "Creature.h"

class Player :
    public Creature
{
public:
    Player(string name, string description, int maxHealth, int attack, int defend, Room* location);
	void Look();
	void Look(string direction);
	void Move(string direction);
	void Take(string object);
	void Drop(string object);
	void Attack(string target);
	void Equip(string object);
	void Loot(string target);
	void Examine();
	void Examine(string object);
	void Inventory();
	void Heal();
	void Stats();
	void Combine(string object1, string object2);

private:
	Item* FindItem(const string& object);

	int maxHealth;
	int defense;

	list<Item*> inventory;
};


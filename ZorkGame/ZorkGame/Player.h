#pragma once
#include "Creature.h"

class Player :
    public Creature
{
public:
    Player(int maxHealth, int defend);
	void Look();
	void Look(string action);
	void Move(string action);
	void Take(string action);
	void Drop(string action);
	void Attack(string action);
	void Equip(string action);
	void Loot(string action);
	void Examine();
	void Examine(string action);
	void Inventory();
	void Heal();
	void Stats();

    int maxHealth;
	int defense;

	list<Item*> inventory;
};


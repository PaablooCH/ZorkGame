#include "Creature.h"

Creature::Creature(string name, string description, int health, int attack, EntityType type, CreatureType creatureType) :
	Entity(name, description, type)
{
	this->health = health;
	this->attack = attack;
	if (health == 0) {
		this->dead = true;
	}
	else {
		this->dead = false;
	}
	this->loot = nullptr;
	this->creatureType = creatureType;
}

void Creature::Damaged(int damage)
{
	health -= damage;
	cout << "You deal " << damage << " to " << name << "." << endl;
	if (health <= 0) {
		dead = true;
		cout << name << " is dead." << endl;
	}
}

void Creature::SetLoot(Item* item)
{
	loot = item;
}

Item* Creature::Loot()
{
	if (!dead) {
		cout << name << " is still alive. Kill it first." << endl;
		return nullptr;
	}
	else if (loot != nullptr) {
		Item* item = loot;
		loot = nullptr;
		return item;
	}
	cout << name << " does not have loot." << endl;
	return nullptr;
}

int Creature::GetHealth()
{
	return health;
}

int Creature::GetAttack()
{
	return attack;
}

Item* Creature::GetLoot()
{
	return loot;
}

bool Creature::isDead()
{
	return this->dead;
}

CreatureType Creature::GetCreatureType()
{
	return creatureType;
}

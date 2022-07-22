#include "Creature.h"

Creature::Creature(int health, int attack) :
	Entity(name, description)
{
	this->health = health;
	this->attack = attack;
	this->isDead = false;
	this->loot = nullptr;
}

void Creature::GetHit(int damage)
{
	health -= damage;
	cout << "You deal " << damage << " to " << name << "." << endl;
	if (health <= 0) {
		isDead = true;
		cout << name << " is dead." << endl;
	}
}

Item* Creature::Loot()
{
	if (!isDead) {
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

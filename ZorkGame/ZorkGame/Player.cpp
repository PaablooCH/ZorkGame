#include "Player.h"

Player::Player(int maxHealth, int attack, int defend, Room* location)
{
	this->maxHealth = maxHealth;
	this->health = maxHealth;
	this->attack = attack;
	this->defend = defend;
	this->location = location;
}

void Player::Look()
{
	cout << location->name << endl;
	cout << location->description << endl;
}

void Player::Look(string action)
{
}

void Player::Move(string action)
{
}

void Player::Take(string action)
{
}

void Player::Drop(string action)
{
}

void Player::Attack(string action)
{
}

void Player::Equip(string action)
{
}

void Player::Loot(string action)
{
}

void Player::Examine()
{
	location->Examine();
}

void Player::Examine(string action)
{
}

void Player::Inventory()
{
	cout << "You have this items in your inventary:" << endl;
	for (list<Item*>::iterator _it = inventory.begin(); _it != inventory.end(); _it++) {
		cout << "  " << (*_it)->name << endl;
	}
	
}

void Player::Stats()
{
	cout << "You have this stats:" << endl;
	cout << "	Healt:" << health << endl;
	cout << "	Attack:" << attack << endl;
	cout << "	Defend:" << defend << endl;
}

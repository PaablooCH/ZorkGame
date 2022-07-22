#include "Player.h"

Player::Player(int maxHealth, int defend, Room* location) :
	Creature(health, attack)
{
	this->maxHealth = maxHealth;
	this->health = maxHealth;
	this->attack = attack;
	this->defense = defend;
	this->location = location;
}

void Player::Look()
{
	cout << location->name << endl;
	cout << location->description << endl;
}

void Player::Look(string direction)
{
	location->Look(direction);
}

void Player::Move(string direction)
{
	Room* newLocation = location->Move(direction);
	if (newLocation != nullptr) {
		cout << location->name << " " << location->description << endl;
		location = newLocation;
	}
	else {
		cout << "You can not move to that direction." << endl;
	}
	//Ir a la room y mirar si existe la direccion si lo hace devolver la habitación segun la exit
}

void Player::Take(string object)
{
	Item* item = location->Take(object);
	if (item != nullptr) {
		cout << "You have picked " << object << "." << endl;
		inventory.push_back(item);
	}
	else {
		cout << "You can not take " << object << "." << endl;
	}
	//Ir a la room y mirar si existe el objeto y devolverlo, eliminarlo de la room
}

void Player::Drop(string object) //TODO vigilar si hay que guardar el item del puntero antes de quitarlo de la lista
{
	for (list<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
		if ((*it)->name == object) {
			cout << "You have dropped the " << object << "." << endl;
			location->contains.push_back(*it);
			inventory.remove(*it);
			return;
		}
	}
	cout << "You do not possess " << object << "." << endl;
	//Ir a la room y dejarle el objeto, eliminar el onjeto del personaje
}

void Player::Attack(string target)
{
	location->Attack(target, attack);
	//Ir a la room y bscar al enemigo, atacar
}

void Player::Equip(string object)
{
	for (list<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
		if ((*it)->name == object) {
			if ((*it)->type == WEAPON) {
				cout << "You have equipped the " << object << ". +" << (*it)->stats << " attack." << endl;
				attack += (*it)->stats;
				inventory.remove(*it);
				return;
			}
			else if ((*it)->type == ARMOUR) {
				cout << "You have equipped the " << object << ". +" << (*it)->stats << " defend." << endl;
				defense += (*it)->stats;
				inventory.remove(*it);
				return;
			}
			cout << "You can not equip the " << object << "." << endl;
		}
	}
	cout << "You do not possess " << object << "." << endl;
	//Ir al inventario y summar los stats
}

void Player::Loot(string target)
{
	Item* loot = location->Loot(target);
	if (loot != nullptr) {
		inventory.push_back(loot);
		cout << "You have obtained " << loot->name << "." << endl;
	}
	//Ir a la room y buscar el cadaver del enemigo
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

void Player::Heal()
{
	for (list<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
		if ((*it)->type == HEAL) {
			health += (*it)->stats;
			if (health > maxHealth) health = maxHealth;
			cout << "You have healed " << (*it)->stats << " points. You have " << health << " HP." << endl;
			return;
		}
	}
}

void Player::Stats()
{
	cout << "You have this stats:" << endl;
	cout << "	Healt:" << health << endl;
	cout << "	Attack:" << attack << endl;
	cout << "	Defend:" << defense << endl;
}

#include "Player.h"

Player::Player(string name, string description, int maxHealth, int attack, int defend, Room* location, EntityType type, CreatureType creatureType) :
	Creature(name, description, maxHealth, attack, type, creatureType)
{
	this->maxHealth = maxHealth;
	this->defense = defend;
	this->location = location;
}

void Player::Look()
{
	cout << location->GetName() << endl;
	cout << location->GetDescription() << endl;
}

void Player::Look(string direction)
{
	location->Look(direction);
}

void Player::Move(string direction)
{
	Exit* exit = location->Move(direction);
	if (exit != nullptr) {
		Item* item = nullptr;
		Item* key = exit->GetKey();
		if (key != nullptr) {
			item = FindItem(key->GetName());
		}
		Room* newLocation = exit->MoveNextRoom(location, item);
		if (newLocation != nullptr) {
			location = newLocation;
			cout << location->GetName() << " " << location->GetDescription() << endl;
		}
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
	Item* item = FindItem(object);
	if (item != nullptr) {
		cout << "You have dropped the " << object << "." << endl;
		location->InsertEntity(item);
		inventory.remove(item);
		return;
	}
	cout << "You do not possess " << object << "." << endl;
	//Ir a la room y dejarle el objeto, eliminar el onjeto del personaje
}

bool Player::Attack(string target)
{
	Creature* creature = location->Attack(target);
	if (creature == nullptr) {
		cout << " You can't attack that." << endl;
		return false;
	}
	if (creature->Damaged(attack)) {
		cout << " You have won the: " << creature->GetName() << endl;
	}
	else {
		int damage = creature->GetAttack() - defense;
		if (damage < 0) damage = 0;
		health -= damage;
		cout << " You have received " << damage << " of dmg" << endl;

		if (health <= 0) {
			cout << " You died. Game over." << endl;
			return true;
		}
	}
	return false;
	//Ir a la room y bscar al enemigo, atacar
}

void Player::Equip(string object)
{
	Item* item = FindItem(object);
	if (item != nullptr) {
		if (item->GetItemType() == WEAPON) {
			cout << "You have equipped the " << object << ". +" << item->GetStats() << " attack." << endl;
			attack += item->GetStats();
			inventory.remove(item);
			delete item;
		}
		else if (item->GetItemType() == ARMOUR) {
			cout << "You have equipped the " << object << ". +" << item->GetStats() << " defend." << endl;
			defense += item->GetStats();
			inventory.remove(item);
			delete item;
		}
		else {
			cout << "You can not equip the " << object << "." << endl;
		}
	}
	else {
		cout << "You do not possess " << object << "." << endl;
	}
	//Ir al inventario y summar los stats
}

bool Player::Loot(string target)
{
	Item* loot = location->Loot(target);
	if (loot != nullptr) {
		inventory.push_back(loot);
		cout << "You have obtained " << loot->GetName() << "." << endl;
		if (loot->GetItemType() == WIN) {
			return true;
		}
	}
	return false;
	//Ir a la room y buscar el cadaver del enemigo
}

void Player::Talk(string npc)
{
	location->Talk(npc);
}

void Player::Examine()
{
	location->Examine();
}

void Player::Examine(string object)
{
	if (location->Examine(object)) {
		return;
	}
	Item* item = FindItem(object);
	if (item != nullptr) {
		cout << item->GetName() << " " << item->GetDescription() << endl;
	}
	else {
		cout << object << " is not in this room." << endl;
	}
}

void Player::Inventory()
{
	cout << "You have these items in your inventary:" << endl;
	for (list<Item*>::iterator _it = inventory.begin(); _it != inventory.end(); _it++) {
		cout << "  " << (*_it)->GetName() << endl;
	}
	
}

void Player::Heal()
{
	for (list<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
		if ((*it)->GetItemType() == HEAL) {
			Item* bandage = (*it);
			health += bandage->GetStats();
			if (health > maxHealth) health = maxHealth;
			cout << "You have healed " << bandage->GetStats() << " points. You have " << health << " HP." << endl;
			inventory.remove(bandage);
			delete (bandage);
			return;
		}
	}
	cout << "Sorry, you do not have heal items." << endl;
}

void Player::Stats()
{
	cout << "You have this stats:" << endl;
	cout << "	Healt:" << health << endl;
	cout << "	Attack:" << attack << endl;
	cout << "	Defend:" << defense << endl;
}

void Player::Combine(string object1, string object2)
{
	Item* item1 = FindItem(object1);
	if (item1 == nullptr) {
		cout << "You do not possess " << object1 << "." << endl;
		return;
	}
	Item* item2 = FindItem(object2);
	if (item2 == nullptr) {
		cout << "You do not possess " << object2 << "." << endl;
		return;
	}
	if (item1->GetItemType() == item2->GetItemType()) {
		cout << "You can not combine two" << item1->GetItemType() << "items." << endl;
		return;
	}
	if (item1->GetItemType() == UPGRADE && item2->GetItemType() == UPGRADE) {
		cout << "You selected 0 upgrade item." << endl;
		return;
	}
	if ((item1->GetItemType() == UPGRADE && (item2->GetItemType() == WEAPON || item2->GetItemType() == ARMOUR)) || 
		((item1->GetItemType() == WEAPON || item1->GetItemType() == ARMOUR) && item2->GetItemType() == UPGRADE)) {
		Item* itemUp = item1->GetItemType() == UPGRADE ? item2 : item1;
		Item* upgrade = item1->GetItemType() == UPGRADE ? item1 : item2;
		itemUp->addStats(upgrade->GetStats());
		cout << "You have obtained +" << upgrade->GetStats() << " in your " << itemUp->GetName() << "!" << endl;
		inventory.remove(upgrade);
		delete upgrade;
		return;
	}
	cout << "You can not combine " << object1 << " with " << object2 << endl;
}

Item* Player::FindItem(const string& object)
{
	for (list<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++) {
		if ((*it)->GetName() == object) {
			return (*it);
		}
	}
	return nullptr;
}

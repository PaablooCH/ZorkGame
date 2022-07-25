#include "Exit.h"

Exit::Exit(const string& name, const string& description, const string& sourceDirection, const string& destinationDirection, Room* source, Room* destination, EntityType type) :
	Entity(name, description, type)
{
	this->sourceDirection = sourceDirection;
	this->destinationDirection = destinationDirection;
	this->source = source;
	this->destination = destination;
	this->locked = false;
	this->key = nullptr;
}

Exit::~Exit()
{
}

void Exit::LookExit(Room* room, string direction)
{
	direction = TranslateDirection(direction);
	if ((room == source && direction == sourceDirection) || (room == destination && direction == destinationDirection)) {
		cout << "In the " << direction << " there is a " << name;
		if (locked) {
			cout << ", but its locked." << " To open it you need " << key->GetName() << ".";
		}
		cout << endl;
	}
}

bool Exit::ExistExit(Room* room, string direction)
{
	direction = TranslateDirection(direction);
	if ((room == source && direction == sourceDirection) || (room == destination && direction == destinationDirection)) {
		return true;
	}
	return false;
}

Room* Exit::MoveNextRoom(Room* room, Item* key)
{
	if (locked) {
		if (!Unlock(key)) {
			cout << "You can not pass. There is a closed door." << endl;
			return nullptr;
		}
	}
	if (source == room) {
		return destination;
	}
	else if (destination == room) {
		return source;
	}
}

bool Exit::Unlock(Item* key)
{
	if (this->key == key) {
		cout << "You have unlocked " << name << "." << endl;
		locked = false;
		return true;
	}
	return false;
}

void Exit::SetKey(Item* key)
{
	this->key = key;
	locked = true;
}

Item* Exit::GetKey()
{
	return key;
}

string Exit::TranslateDirection(const string& direction)
{
	if (direction == "north" || direction == "n") {
		return "north";
	}
	if (direction == "west" || direction == "w") {
		return "west";
	}
	if (direction == "south" || direction == "s") {
		return "south";
	}
	else {
		return "east";
	}
}

#include "Exit.h"

Exit::Exit(const string& sourceDirection, const string& destinationDirection, Room* source, Room* destination, bool locked) :
	Entity(name, description)
{
	this->sourceDirection = sourceDirection;
	this->destinationDirection = destinationDirection;
	this->source = source;
	this->destination = destination;
	this->locked = locked;
}

Exit::~Exit()
{
}

void Exit::ExistExit(Room* room, string direction)
{
	direction = TranslateDirection(direction);
	if ((room == source && direction == sourceDirection) || (room == destination && direction == destinationDirection)) {
		cout << "In the " << direction << " there is a " << name;
		if (locked) {
			cout << ", but its locked.";
		}
		cout << endl;
	}
}

Room* Exit::MoveNextRoom(Room* room)
{
	if (locked) {
		cout << "You can not pass. There is a closed door." << endl;
		return nullptr;
	}
	if (source == room) {
		return destination;
	}
	else {
		return source;
	}
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
	if (direction == "east" || direction == "e") {
		return "east";
	}
}

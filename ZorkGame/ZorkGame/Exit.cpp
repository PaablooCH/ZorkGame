#include "Exit.h"

Exit::Exit(const string& direction, Room* source, Room* destination)
{
	this->direction = direction;
	this->source = source;
	this->destination = destination;
}

Exit::~Exit()
{
}

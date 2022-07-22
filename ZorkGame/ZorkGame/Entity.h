#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

enum EntityType
{
	roomExit,
	room,
	item,
	creature
};
class Entity
{
public:
	Entity(const string& name, const string& description);
	~Entity();

	EntityType type;
	string name;
	string description;

	list<Entity*> contains;
};


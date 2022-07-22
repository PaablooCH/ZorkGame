#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

enum EntityType
{
	EXIT,
	ROOM,
	ITEM,
	CREATURE
};
class Entity
{
public:
	Entity(const string& name, const string& description, Entity* parent);
	Entity(const string& name, const string& description);
	~Entity();

	EntityType type;
	string name;
	string description;

	list<Entity*> contains;

	Entity* parent; //Right now, only items has parents
};


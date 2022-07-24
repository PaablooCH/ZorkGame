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
	Entity(const string& name, const string& description);
	~Entity();
	string GetName();
	EntityType GetType();
	string GetDescription();
	list<Entity*> GetContains();
	void InsertEntity(Entity* entity);

protected:
	EntityType type;
	string name;
	string description;

	list<Entity*> contains;
};


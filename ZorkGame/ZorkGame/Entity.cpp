#include "Entity.h"

Entity::Entity(const string& name, const string& description, Entity* parent)
{
	this->name = name;
	this->description = description;
	this->parent = parent;
}

Entity::Entity(const string& name, const string& description)
{
	this->name = name;
	this->description = description;
}

Entity::~Entity()
{
}

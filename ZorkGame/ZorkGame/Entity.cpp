#include "Entity.h"

Entity::Entity(const string& name, const string& description, EntityType entitytype)
{
	this->name = name;
	this->description = description;
	this->type = entitytype;
}

Entity::~Entity()
{
}

string Entity::GetName()
{
	return name;
}

EntityType Entity::GetType()
{
	return type;
}

string Entity::GetDescription()
{
	return description;
}

list<Entity*> Entity::GetContains()
{
	return contains;
}

void Entity::InsertEntity(Entity* entity)
{
	contains.push_back(entity);
}

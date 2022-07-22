#include "Item.h"

Item::Item(const string& name, const string& description, ItemType itemType, Entity* parent) :
	Entity(name, description, parent)
{
	this->name = name;
	this->description = description;
	this->itemType = itemType;
	this->parent = parent;
}

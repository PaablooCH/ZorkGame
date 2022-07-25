#include "Item.h"

Item::Item(const string& name, const string& description, ItemType itemType, EntityType type) :
	Entity(name, description, type)
{
	this->itemType = itemType;
	this->stats = 0;
}

Item::Item(const string& name, const string& description, int stats, ItemType itemType, EntityType type) :
Entity(name, description, type)
{
	this->itemType = itemType;
	this->stats = stats;
}

Item::~Item()
{
}

int Item::GetStats()
{
	return stats;
}

ItemType Item::GetItemType()
{
	return itemType;
}

void Item::addStats(int stat)
{
	stats += stat;
}

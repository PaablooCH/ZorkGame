#include "Item.h"

Item::Item(const string& name, const string& description, ItemType itemType) :
	Entity(name, description)
{
	this->itemType = itemType;
	this->stats = 0;
	this->itemToCombine = nullptr;
}

Item::Item(const string& name, const string& description, int stats, ItemType itemType) :
Entity(name, description)
{
	this->itemType = itemType;
	this->stats = stats;
	this->itemToCombine = nullptr;
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

void Item::SetCombination(Item* itemToCombine, Item* resultItem)
{
	this->itemToCombine = itemToCombine;
	this->resultItem = resultItem;
}

bool Item::CanCombine(Item* item)
{
	return item == itemToCombine;
}

Item* Item::GetResult()
{
	return resultItem;
}

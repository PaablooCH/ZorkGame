#pragma once
#include "Entity.h"

enum ItemType
{
	KEY,
	WEAPON,
	ARMOUR,
	HEAL
};


class Item :
    public Entity
{
public:
	Item(const string& name, const string& description, ItemType itemType);
	Item(const string& name, const string& description, int stats, ItemType itemType);
	~Item();
	int GetStats();
	ItemType GetItemType();
	void SetCombination(Item* itemToCombine, Item* resultItem);
	bool CanCombine(Item* item);
	Item* GetResult();

private:
	ItemType itemType;
	int stats;
	Item* itemToCombine;
	Item* resultItem;
};


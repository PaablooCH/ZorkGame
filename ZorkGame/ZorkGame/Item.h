#pragma once
#include "Entity.h"

enum ItemType
{
	KEY,
	WEAPON,
	ARMOUR,
	HEAL,
	UPGRADE
};

class Item :
    public Entity
{
public:
	Item(const string& name, const string& description, ItemType itemType, EntityType type);
	Item(const string& name, const string& description, int stats, ItemType itemType, EntityType type);
	~Item();
	int GetStats();
	ItemType GetItemType();
	void addStats(int stat);

private:
	ItemType itemType;
	int stats;
};


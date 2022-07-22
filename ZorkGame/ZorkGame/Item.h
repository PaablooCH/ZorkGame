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
	Item(const string& name, const string& description, ItemType itemType, Entity* parent);
	~Item();

	ItemType itemType;
	int stats;
};


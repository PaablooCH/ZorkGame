#pragma once
#include "Entity.h"
#include "Item.h"
#include "Room.h"

class Room;

class Creature :
    public Entity
{
public:
    Creature(int health, int attack, Room* location);
    void GetHit(int damage);
    Item* Loot();

    Room* location;
    int health;
    int attack;
    bool isDead;
    Item* loot;
};


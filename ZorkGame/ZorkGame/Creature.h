#pragma once
#include "Entity.h"
#include "Room.h"

class Creature :
    public Entity
{
public:
    Creature(int health, int attack);
    void GetHit(int damage);
    Item* Loot();

    Room* location;
    int health;
    int attack;
    bool isDead;
    Item* loot;
};


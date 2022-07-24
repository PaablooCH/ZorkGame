#pragma once
#include "Entity.h"
#include "Item.h"
#include "Room.h"


class Creature :
    public Entity
{
public:
    Creature(string name, string description, int health, int attack, Room* location);
    void Damaged(int damage);
    Item* Loot();
    int GetHealth();
    int GetAttack();
     
protected:

    Room* location;
    int health;
    int attack;
    bool isDead;
    Item* loot;
};


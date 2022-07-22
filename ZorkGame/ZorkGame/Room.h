#pragma once
#include "Entity.h"
#include "Exit.h"
#include "Item.h"
#include "Creature.h"

class Room :
    public Entity
{
public:
    Room();
    void Examine();
    void Look(string action);
    Room* Move(string direction);
    Item* Take(string object);
    Item* Loot(string target);
    void Attack(string target, int damage);
    
    list<Exit*> exits;
private:
    Item* FindItem(string object);
    Exit* FindExit(string direction);
    Creature* FindCreature(string target);
};


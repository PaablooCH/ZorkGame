#pragma once
#include "Entity.h"
#include "Exit.h"
#include "Item.h"
#include "Creature.h"

class Creature;

class Room :
    public Entity
{
public:
    Room(string name, string description, EntityType type);
    void Examine();
    bool Examine(const string& object);
    void Look(const string& direction);
    Room* Move(const string& direction);
    Item* Take(const string& object);
    Item* Loot(const string& target);
    void Talk(const string& npc);
    void Attack(const string& target, const int& damage);
    
private:
    Item* FindItem(const string& object);
    Exit* FindExit(const string& direction);
    Creature* FindCreature(const string& target);
    Entity* FindEntity(const string& target);
};


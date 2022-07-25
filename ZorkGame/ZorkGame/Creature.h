#pragma once
#include "Entity.h"
#include "Item.h"
#include "Room.h"

enum CreatureType
{
    ENEMY,
    PLAYER,
    NPC
};

class Creature :
    public Entity
{
public:
    Creature(string name, string description, int health, int attack, EntityType type, CreatureType creatureType);
    void Damaged(int damage);
    void SetLoot(Item* item);
    Item* Loot();
    int GetHealth();
    int GetAttack();
    Item* GetLoot();
    bool isDead();
    CreatureType GetCreatureType();
     
protected:

    int health;
    int attack;
    bool dead;
    Item* loot;
    CreatureType creatureType;
};
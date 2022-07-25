#pragma once
#include "Creature.h"
#include <list>

class Npc :
    public Creature
{
public:
    Npc(string name, string description, int maxHealth, int attack, EntityType type, CreatureType creatureType);
    void Talk();
    void addDialog(string dialog);
private:
    list<string> dialog;
};


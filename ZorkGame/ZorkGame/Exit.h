#pragma once
#include "Entity.h"
#include "Room.h"

class Exit :
    public Entity
{
public:
    Exit(const string& direction, Room* source, Room* destination);
    ~Exit();

    string direction;
    Room* source;
    Room* destination;
    
};


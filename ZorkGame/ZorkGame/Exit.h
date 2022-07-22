#pragma once
#include "Entity.h"

class Room;

class Exit :
    public Entity
{
public:
    Exit(const string& direction, const string& inversDirection, Room* source, Room* destination, bool locked = false);
    ~Exit();
    void ExistExit(Room* room, string direction);
    Room* MoveNextRoom(Room* room);

    string sourceDirection;
    string destinationDirection;
    Room* source;
    Room* destination;
private:
    string TranslateDirection(const string& direction);
    bool locked;
    
};


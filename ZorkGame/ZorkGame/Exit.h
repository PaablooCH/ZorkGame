#pragma once
#include "Entity.h"
#include "Item.h"

class Room;

class Exit :
    public Entity
{
public:
    Exit(const string& name, const string& description, const string& sourceDirection, const string& destinationDirection, Room* source, Room* destination, EntityType type);
    ~Exit();
    void LookExit(Room* room, string direction);
    bool ExistExit(Room* room, string direction);
    Room* MoveNextRoom(Room* room);
    bool Unlock(Item* key);
    void setKey(Item* key);

    
private:
    string TranslateDirection(const string& direction);
    
    string sourceDirection;
    string destinationDirection;
    Room* source;
    Room* destination;
    bool locked;
    Item* key;

    
};


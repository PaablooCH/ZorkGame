#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "Entity.h"
#include "Player.h"
#include "Creature.h"

using namespace std;

class World
{
public:
	World();
	~World();
	bool Update(const vector<string>& actions);
	bool gameOver;
	bool win;
private:
	bool isADirection(const string& direction);
	list<Entity*> entities;
	Player* player;
};


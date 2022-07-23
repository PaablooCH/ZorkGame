#pragma once
#include <iostream>
#include <vector>
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
private:
	bool isADirection(const string& direction);
	vector<Entity*> entities;
	Player* player;
};


#pragma once
#include <vector>
#include "Entity.h"
#include "Player.h"

using namespace std;

class World
{
public:
	World();
	~World();
	bool Update(const vector<string>& actions);
private:
	vector<Entity*> entities;
	Player* player;
};


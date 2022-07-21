#include "World.h"

World::World()
{
	// Player
	player = new Player();
}

World::~World()
{
}

bool World::Update(const vector<string>& actions)
{
	switch (actions.size())
	{
	case 1:
		break;
	default:
		break;
	}
	return false;
}

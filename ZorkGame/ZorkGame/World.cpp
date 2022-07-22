#include "World.h"

World::World()
{
	Room* jail = new Room();
	// Player
	player = new Player(20, 2, 0, jail);
}

World::~World()
{
}

bool World::Update(const vector<string>& actions)
{
	switch (actions.size())
	{
	case 1:
		if (actions[0] == "look" || actions[0] == "l") {
			player->Look();
			return true;
		}
		else if (actions[0] == "examine" || actions[0] == "e") {
			player->Examine();
			return true;
		}
		else if (actions[0] == "inventory" || actions[0] == "i") {
			player->Inventory();
			return true;
		}
		else if (actions[0] == "quit" || actions[0] == "q") {
			gameOver = true;
			return true;
		}
		else if (actions[0] == "stats" || actions[0] == "s") {
			player->Stats();
			return true;
		}
		break;
	case 2:
	{
		if (actions[0] == "look" || actions[0] == "l") {
			if (isADirection(actions[1])) {
				player->Look(actions[1]);
			}
			else {
				cout << "Sorry but " << actions[1] << "is not a direction." << endl;
			}
		}
		else if (actions[0] == "move" || actions[0] == "m") {
			if (isADirection(actions[1])) {
				player->Move(actions[1]);
			}
			else {
				cout << "Sorry but " << actions[1] << "is not a direction." << endl;
			}
		}
		else if (actions[0] == "pick" || actions[0] == "p") {
			player->Take(actions[1]);
		}
		else if (actions[0] == "drop" || actions[0] == "d") {
			player->Drop(actions[1]);
		}
		else if (actions[0] == "equip" || actions[0] == "eq") {
			player->Equip(actions[1]);
		}
		else if (actions[0], "examine" || actions[0] == "ex") {
			player->Examine(actions[1]);
		}
		else if (actions[0] == "attack" || actions[0] == "at") {
			player->Attack(actions[1]);
		}
		else if (actions[0] == "loot" || actions[0] == "lt") {
			player->Loot(actions[1]);
		}
		break;
	}
	default:
		break;
	}
	return false;
}

bool World::isADirection(const string& direction)
{
	if (direction == "north" || direction == "n") {
		return true;
	}
	if (direction == "west" || direction == "w") {
		return true;
	}
	if (direction == "south" || direction == "s") {
		return true;
	}
	if (direction == "east" || direction == "e") {
		return true;
	}
	return false;
}

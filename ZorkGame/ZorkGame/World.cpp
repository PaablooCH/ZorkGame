#include "World.h"
#include "npc.h"

World::World()
{

	// Rooms
	Room* jail = new Room("Jail", "Only a small candle allows you to see away from your fingers.", ROOM);
	Room* mainHall = new Room("Main hall", "The main hall is a mess, the walls and floor are painted red, you dont know what it is, but you don't want to know it neither.", ROOM);
	Room* throne = new Room("Throne", "Here is were the king should be.", ROOM);
	Room* basement = new Room("Basement", "The basement features old furniture and dim light.", ROOM);

	entities.push_back(jail);
	entities.push_back(mainHall);
	entities.push_back(throne);
	entities.push_back(basement);

	// Exits
	Exit* ex1 = new Exit("Stairs", "These stairs connect the jail with the main hall.", "north", "south", jail, mainHall, EXIT);
	Exit* ex2 = new Exit("Door", "This door connect the main hall with the throne.", "west", "east", mainHall, throne, EXIT);

	jail->InsertEntity(ex1);
	mainHall->InsertEntity(ex1);
	mainHall->InsertEntity(ex2);
	throne->InsertEntity(ex2);
	
	entities.push_back(ex1);
	entities.push_back(ex2);

	// Creatures
	Creature* knightGroup = new Creature("Knight group", "It's a group of knights, some of them look scared.", 7, 1, CREATURE, ENEMY);
	Creature* corpse = new Creature("Corpse", "There is a human corpse leaning against the wall. Somebody has killed him.", 0, 0, CREATURE, ENEMY);

	jail->InsertEntity(corpse);
	mainHall->InsertEntity(knightGroup);

	entities.push_back(knightGroup);
	entities.push_back(corpse);

	// NPC

	Npc* npc = new Npc("Knight", "His armor its destroyed, you don't want to end up like him.", 1, 0, CREATURE, NPC);
	npc->addDialog("Leave me please.");
	npc->addDialog("Leave me here and try to scape.");
	npc->addDialog("Oh, you're the prisoner, how did you end up here?");

	throne->InsertEntity(npc);

	// Items
	
	Item* key = new Item("Key", "An old rusty key.", KEY, ITEM);
	Item* chest = new Item("Chest", "An old rusty chest.", CRAFT, ITEM);
	
	npc->SetLoot(key);

	Item* sword = new Item("Sword", "A simple old and rusty sword.", 6, WEAPON, ITEM);

	Item* stick = new Item("Stick", "A strick", CRAFT, ITEM);
	Item* metal = new Item("Blade", "It's sharp", CRAFT, ITEM);
	stick->SetCombination(metal, sword);
	metal->SetCombination(stick, sword);

	key->SetCombination(chest, metal);
	chest->SetCombination(key, metal);

	Item* bandage = new Item("Bandage", "You can recover health with it.", 8, HEAL, ITEM);
	knightGroup->SetLoot(bandage);

	Item* shield = new Item("Shield", "An old wooden shield.", 3, ARMOUR, ITEM);

	entities.push_back(key);
	entities.push_back(sword);
	entities.push_back(stick);
	entities.push_back(metal);
	entities.push_back(bandage);
	entities.push_back(shield);

	// Player
	player = new Player("Hero", "You are an awesome adventurer!", 25, 5, 5, jail, CREATURE, PLAYER);
	entities.push_back(player);
	gameOver = false;
}

World::~World()
{
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		delete* it;

	entities.clear();
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
		else if (actions[0] == "heal" || actions[0] == "h") {
			player->Heal();
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
				cout << "Sorry but " << actions[1] << " is not a direction." << endl;
			}
			return true;
		}
		else if (actions[0] == "move" || actions[0] == "m") {
			if (isADirection(actions[1])) {
				player->Move(actions[1]);
			}
			else {
				cout << "Sorry but " << actions[1] << "is not a direction." << endl;
			}
			return true;
		}
		else if (actions[0] == "pick" || actions[0] == "p") {
			player->Take(actions[1]);
			return true;
		}
		else if (actions[0] == "drop" || actions[0] == "d") {
			player->Drop(actions[1]);
			return true;
		}
		else if (actions[0] == "talk" || actions[0] == "t") {
			player->Talk(actions[1]);
			return true;
		}
		else if (actions[0] == "equip" || actions[0] == "eq") {
			player->Equip(actions[1]);
			return true;
		}
		else if (actions[0] == "examine" || actions[0] == "e") {
			player->Examine(actions[1]);
			return true;
		}
		else if (actions[0] == "attack" || actions[0] == "at") {
			player->Attack(actions[1]);
			return true;
		}
		else if (actions[0] == "loot" || actions[0] == "lt") {
			player->Loot(actions[1]);
			return true;
		}
		break;
	}
	case 3:
	{
		if (actions[0] == "combine" || actions[0] == "c") {
			player->Combine(actions[1], actions[2]);
			return true;
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



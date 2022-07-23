#include <iostream>
#include <string>
#include <vector>

#include "World.h"
#include "ZorkGame.h"

using namespace std;

vector<string> getActions(const string& input) {
	vector<string> actions;
	string temp = "";
	for (int i = 0;i < input.length();++i) {

		if (input[i] == ' ') {
			actions.push_back(temp);
			temp = "";
		}
		else {
			temp.push_back(input[i]);
		}

	}
	actions.push_back(temp);
	return actions;
}

int main()
{
	string player_input;
	vector<string> actions;
	actions.reserve(10);

	cout << "Welcome to MyZork!" << endl;
	cout << "----------------\n";

	World world;

	actions.push_back("look");

	while (1)
	{
		cout << endl << ">";

		getline(cin, player_input);
		actions = getActions(player_input);

		if (!world.Update(actions)) cout << "Sorry, I'm a little deaf. Can you repeat?" << endl;

		if (world.gameOver) break;
	}
	cout << "Thanks for playing :)" << endl;
}

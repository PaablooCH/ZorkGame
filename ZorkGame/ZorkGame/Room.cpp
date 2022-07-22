#include "Room.h"

Room::Room()
{
}

void Room::Examine()
{
	if (contains.size() == 0) {
		cout << "The room is empty." << endl;
		return;
	}
	cout << "This room contains:" << endl;
	for (list<Entity*>::iterator _it = contains.begin(); _it != contains.end(); _it++) {
		cout << "	" << (*_it)->name << endl;
	}

}

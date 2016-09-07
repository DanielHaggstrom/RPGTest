#ifndef PLAYER
#define PLAYER

#include <string>
#include <fstream>
#include "ItemList.h"

class Player
{
private:

	std::string id;
	int health;
	int power;

	ItemList items;

public:

	std::string getId() { return id; }
	int getHealth() { return health; }
	int getPower() { return power; }

	ItemList getItems() { return items; }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

#endif
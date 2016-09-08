#ifndef PLAYER
#define PLAYER

#include <string>
#include <fstream>
#include "Objects.h"
#include "ItemList.h"
#include "GlobalConstants.h"

class Player
{
private:

	std::string id;
	int health;
	int power;

	ItemList items;

	void loadItems(Objects objects);

public:

	Player() {}
	Player(std::string newId, Objects objects) : id(newId), health(HEALTH), power(POWER) { loadItems(objects); }
	~Player() {}

	std::string getId() { return id; }
	int getHealth() { return health; }
	int getPower() { return power; }

	ItemList getItems() { return items; }

	void setHealth(int number) { health = number; }
	void setPower(int number) { power = number; }

	void setItem(std::string id, bool sign)
	{
		switch (sign)
		{
		case true:

			items.get(id)->increase();
			break;

		case false:

			items.get(id)->decrease();
			break;
		}
	}

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

#endif
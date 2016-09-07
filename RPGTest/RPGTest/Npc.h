#ifndef ENEMY
#define ENEMY

#include <string>
#include <fstream>

class NPC
{
private:

	std::string id;
	int health;
	int power;

public:

	std::string getId() { return id; }
	int getHealth() { return health; }
	int getPower() { return power; }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

#endif
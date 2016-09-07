#ifndef GAME
#define GAME

#include "Player.h"
#include <fstream>
#include <string>

class Game
{
private:

	Player player;
	std::string id;
	std::string quest;

public:

	Game() {}

	Game(Player newplayer): player(newplayer), 
		id(player.getId()), quest("Beguin") {}

	std::string getId() { return id; }
	Player getPlayer() { return player; }
	std::string getQuest() { return quest; }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

#endif
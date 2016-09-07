#ifndef GAME
#define GAME

#include "Player.h"
#include <fstream>
#include <string>

struct Game
{
	Player player;
	std::string id;
	std::string quest;

	Game() {}

	Game(Player newplayer): player(newplayer), 
		id(player.getId()), quest("Beguin") {}

	std::string getId() { return id; }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

bool Game::load(std::ifstream &file)
{
	file >> id;

	if (!file.fail())
	{
		file >> quest;

		if (!file.fail())
		{
			if (player.load(file)) return true;

			else return false;
		}
		else return false;
	}
	else return false;
}

void Game::save(std::ofstream &file)
{
	file << id << std::endl
		<< quest << std::endl;

	player.save(file);
}

#endif
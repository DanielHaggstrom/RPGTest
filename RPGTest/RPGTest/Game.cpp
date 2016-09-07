#include "Game.h"

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
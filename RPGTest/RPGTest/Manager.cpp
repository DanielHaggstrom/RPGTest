#include "GraphInter.h"
#include "Manager.h"
#include <sstream>

Manager* Manager::manager = nullptr;

Manager::Manager(const std::string &new_domain) :
domain(new_domain)
{
	if (manager == nullptr)
	{
		manager = this;
		bootUp();
	}
}

Manager::~Manager()
{
	shutDown();
}

void Manager::bootUp()
{
	std::ostringstream quest_file, 
		enemy_file, game_file, object_file;

	game_file << domain << "_game.txt";
	quest_file << domain << "_quest.txt";
	enemy_file << domain << "_enemy.txt";
	object_file << domain << "_object.txt";

	games.load(game_file.str());
	quests.load(quest_file.str());
	enemies.load(enemy_file.str());
	objects.load(object_file.str());
}

void Manager::shutDown()
{
	std::ostringstream quest_file,
		enemy_file, game_file, object_file;

	game_file << domain << "_game.txt";
	quest_file << domain << "_quest.txt";
	enemy_file << domain << "_enemy.txt";
	object_file << domain << "_object.txt";

	games.save(game_file.str());
	quests.save(quest_file.str());
	enemies.save(enemy_file.str());
	objects.save(object_file.str());
}

Game* Manager::newGame(Objects objects, GameList games)
{
	Player newPlayer;
	std::string name = "";
	bool right;

	do
	{
		right = true;

		name = GraphInter::get()->valid_user();

		if (games.get(name))
		{
			GraphInter::get()->display("Error, there is already a user with this name");

			right = false;
		}

	} while (!right);

	if (name != "")
	{
		newPlayer = Player(name, objects);

		return &Game(newPlayer);
	}
	else return nullptr;
}

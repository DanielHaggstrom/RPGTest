#include "UtilsWin.h"
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
		enemy_file, game_file;

	game_file << domain << "_game.txt";
	quest_file << domain << "_quest.txt";
	enemy_file << domain << "_enemy.txt";

	if (!games.load(game_file.str())) message("Could not load Games");
	if (!quests.load(quest_file.str())) message("Could not load Quests");
	if (!enemies.load(enemy_file.str())) message("Could not load Enemies");
}

void Manager::shutDown()
{
	std::ostringstream quest_file, 
		enemy_file, game_file;

	game_file << domain << "_game.txt";
	quest_file << domain << "_quest.txt";
	enemy_file << domain << "_enemy.txt";

	games.save(game_file.str());
	quests.save(quest_file.str());
	enemies.save(enemy_file.str());
}

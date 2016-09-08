#ifndef MANAGER
#define MANAGER

#include "QuestList.h"
#include "GameList.h"
#include "NPCLists.h"
#include "Objects.h"
#include <string>

class Manager
{
private:

	static Manager* manager;

	std::string domain;
	QuestList quests;
	NPCList enemies;
	Objects objects;
	GameList games;

	void shutDown();
	void bootUp();

public:

	Manager(const std::string &new_domain);
	~Manager();

	static Manager* getManager() { return manager; }

	QuestList* getQuests() { return &quests; }
	NPCList* getEnemies() { return &enemies; }
	Objects* getObjects() { return &objects; }
	GameList* getGames() { return &games; }

	Game* newGame(Objects objects, GameList games);
};

#endif
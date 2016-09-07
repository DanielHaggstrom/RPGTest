#ifndef MANAGER
#define MANAGER

#include "QuestList.h"
#include "ItemList.h"
#include "GameList.h"
#include "NPCLists.h"
#include <string>

class Manager
{
private:

	static Manager* manager;

	std::string domain;
	QuestList quests;
	NPCList enemies;
	ItemList items;
	GameList games;

	void shutDown();
	void bootUp();

public:

	Manager(const std::string &new_domain);
	~Manager();

	static Manager* getManager() { return manager; }

	QuestList* getQuests() { return &quests; }
	NPCList* getEnemies() { return &enemies; }
	ItemList* getItems() { return &items; }
	GameList* getGames() { return &games; }
};

#endif
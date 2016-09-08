#include "GraphInter.h"
#include "utilsWin.h"
#include "Session.h"

Session::Session(Manager* manager) :
manager(manager)
{
	int option;

	GraphInter::load();

	do
	{
		GraphInter::get()->clearConsole();
		option = GraphInter::get()->mainMenu(*manager->getGames());
		GraphInter::get()->clearConsole();

		if (option <= 3)
		{
			if (option >= manager->getGames()->length())
			{
				game = manager->newGame(*manager->getObjects(), *manager->getGames());
				if (game != nullptr) launch(*manager->getQuests());
				break;
			}
			else
			{
				game = manager->getGames()->operator[](option);
				if (game != nullptr) launch(*manager->getQuests());
				break;
			}
		}
	} while (option != 4);
}

Session::~Session()
{
	GraphInter::close();
}


void Session::launch(QuestList quests)
{
	bool death = false, end = false;
	int option;

	do
	{
		if (game->getQuest() == "End") end = true;

		option = GraphInter::get()->QuestMenu(*quests.get(game->getQuest()));

		game->setQuest(quests.get(game->getQuest())->getOptions()[option]);

		switch (quests.get(game->getQuest())->getMod().stat)
		{
		case Health:

			switch (quests.get(game->getQuest())->getMod().positive)
			{
			case true:

				game->getPlayer().setHealth(game->getPlayer().getHealth() + quests.get(game->getQuest())->getMod().HowMany);
				break;

			case false:

				game->getPlayer().setHealth(game->getPlayer().getHealth() - quests.get(game->getQuest())->getMod().HowMany);

				if (game->getPlayer().getHealth() <= 0) death = true;
				break;
			}
		case Power:

			switch (quests.get(game->getQuest())->getMod().positive)
			{
			case true:

				game->getPlayer().setHealth(game->getPlayer().getPower() + quests.get(game->getQuest())->getMod().HowMany);
				break;

			case false:

				game->getPlayer().setHealth(game->getPlayer().getPower() - quests.get(game->getQuest())->getMod().HowMany);

				if (game->getPlayer().getPower() <= 0) death = true;
				break;
			}
			game->getPlayer().setItem(quests.get(game->getQuest())->getGetItem().id, quests.get(game->getQuest())->getGetItem().sign);
		}
	} while (!death && !end);

	//end();
}
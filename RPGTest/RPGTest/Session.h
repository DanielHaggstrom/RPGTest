#ifndef SESSION
#define SESSION

#include  "Manager.h"
#include "Game.h"

/*----------------------------
This class is responsible for the user session,
for what he can do on it
------------------------------*/

class Session
{
private:

	Manager* manager;
	Game* game;

	void launch(QuestList quests);

public:

	Session(Manager* manager);
	~Session();

	Manager* getManager() { return manager; }
	Game* getGame() { return game; }
};

#endif
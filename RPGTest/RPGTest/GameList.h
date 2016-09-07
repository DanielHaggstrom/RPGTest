#ifndef GAMELIST
#define GAMELIST

#include "MainList.h"
#include "Game.h"

class GameList : public List<Game> 
{
public:

	bool insert(Game* newGame)
	{
		if (newGame != nullptr)
		{
			list[counter++] = newGame;
			return true;
		}
		else return false;
	}
};

#endif
#ifndef MAP
#define MAP

#include <string>
#include <fstream>
#include "Board.h"

class Map
{

private:

	std::string id;
	Board board;

public:

	Map() {};
	~Map() {};

	std::string getId() { return id; }
	Board getBoard() { return board; }

	bool load(std::ifstream &file)
	{
		file >> id;

		if (!file.fail())
		{
			if (board.load(file)) return true;

			else return false;
		}
		else return false;
	}

	void save(std::ofstream &file)
	{
		file << id << std::endl;

		board.save(file);
	}
};

#endif
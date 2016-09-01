#include <string>
#include "Board.h"
#include <fstream>


struct Map
{
	std::string id;
	Board board;

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
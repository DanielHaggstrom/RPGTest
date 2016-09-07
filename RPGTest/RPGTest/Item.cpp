#include "Item.h"

bool Item::load(std::ifstream &file)
{
	file >> id;

	if (!file.fail())
	{
		file >> HowMany;

		if (file.fail()) return true;

		else return false;
	}
	else return false;
}

void Item::save(std::ofstream &file)
{
	file << id << " " << HowMany << std::endl;
}
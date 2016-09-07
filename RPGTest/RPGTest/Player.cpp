#include "Player.h"

bool Player::load(std::ifstream &file)
{
	file >> id;

	if (!file.fail())
	{
		file >> health;

		if (!file.fail())
		{
			file >> power;

			if (!file.fail())
			{
				items.load(file);

				if (!file.fail()) return true;

				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

void Player::save(std::ofstream &file)
{
	file << id << std::endl
		<< health << std::endl
		<< power << std::endl;
}
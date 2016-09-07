#ifndef PLAYER
#define PLAYER

#include <string>
#include <fstream>

struct Player
{
	std::string id;
	int health;
	int power;

	std::string getId() { return id; }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

bool Player::load(std::ifstream &file)
{
	file >> id;

	if (!file.fail())
	{
		file >> health;

		if (!file.fail())
		{
			file >> power;

			if (!file.fail()) return true;

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

#endif
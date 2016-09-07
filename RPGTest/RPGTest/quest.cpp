#include "quest.h"
#include "QuestList.h"

Quest::Quest(const std::string newid, std::string newdescription, std::vector<std::string> newoptions) :
id(newid), description(newdescription), options(newoptions) {}

bool Quest::load(std::ifstream &file)
{
	int n;
	std::string option;

	std::getline(file, id);

	if (!file.fail())
	{
		std::getline(file, description);

		if (!file.fail())
		{
			file >> n;

			if (!file.fail())
			{
				for (int i = 0; i < n && !file.fail(); i++)
				{
					std::getline(file, option);

					if (!file.fail())
					{
						options.push_back(option);
					}
					else return false;
				}
				return true;
			}
			else return false;
		}
		else return false;
	}
	else return false;
}

void Quest::save(std::ofstream &file)
{
	file << id << std::endl
		<< description << std::endl
		<< options.size() << std::endl;

	for (int i = 0; i < options.size(); i++)
	{
		file << options[i] << std::endl;
	}
}
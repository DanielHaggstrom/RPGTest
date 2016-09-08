#ifndef QUEST_H
#define QUEST_H

#include <fstream>
#include <string>
#include <vector>

class QuestList;

enum Stats { Health, Power, None };

struct Mod
{
	Stats stat;
	int HowMany;
	bool positive;

	Mod(Stats newStat, int counter, bool sign) : stat(newStat), HowMany(counter), positive(sign) {}
	Mod() {}

	bool load(std::ifstream &file)
	{
		int n;

		file >> n;

		if (!file.fail())
		{
			stat = Stats(n);

			file >> HowMany;

			if (!file.fail())
			{
				file >> positive;

				if (!file.fail()) return true;

				else return false;
			}
			else return false;
		}
		else return false;
	}

	void save(std::ofstream &file)
	{
		file << stat << " " << HowMany << " " 
			<< positive << std::endl;
	}
};

struct GetItem
{
	std::string id;
	bool sign;

	GetItem(std::string newId, bool positive) : id(newId), sign(positive) {}
	GetItem() {}

	bool load(std::ifstream &file)
	{
		file >> id;

		if (file.fail())
		{
			file >> sign;

			if (!file.fail()) return true;

			else return false;
		}
		else return false;
	}

	void save(std::ofstream &file)
	{
		file << id << " " 
			<< " " << sign 
			<< std::endl;
	}
};

class Quest
{
private:

	Mod mod;
	GetItem item;
	std::string id;
    std::string description;
	std::vector<std::string> options;

public:

	Quest() {};
    Quest(std::string id, std::string description, std::vector<std::string> options);
	~Quest() {};

	Mod getMod() { return mod; }
	std::string getId(){ return id; }
	GetItem getGetItem() { return item; }
	std::string getDescription(){ return description; }
	std::vector<std::string> getOptions() { return options; }

	void setId(std::string newId){ id = newId; }
	void setOptions(std::vector<std::string> newOptions){ options = newOptions; }
	void setDescription(std::string newDescription){ description = newDescription; }
	void setMod(Stats stat, int counter, bool sign) { mod = Mod(stat, counter, sign); }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

#endif

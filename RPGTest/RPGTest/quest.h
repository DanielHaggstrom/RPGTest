#ifndef QUEST_H
#define QUEST_H

#include <fstream>
#include <string>
#include <vector>

class QuestList;

class Quest
{
private:

	std::string id;
    std::string description;
	std::vector<std::string> options;

public:

	Quest() {};
    Quest(std::string id, std::string description, std::vector<std::string> options);
	~Quest() {};

	std::string getId(){ return id; }
	std::string getDescription(){ return description; }
	std::vector<std::string> getOptions() { return options; }

	void setId(std::string newId){ id = newId; }
	void setDescription(std::string newDescription){ description = newDescription; }
	void setOptions(std::vector<std::string> newOptions){ options = newOptions; }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

#endif

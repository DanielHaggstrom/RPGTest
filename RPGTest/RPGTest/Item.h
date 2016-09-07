#ifndef ITEM
#define ITEM

#include <string>
#include <fstream>

class Item
{
private:

	std::string id;
	int HowMany;

public:

	std::string getId() { return id; }
	int getHowMany() { return HowMany; }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

#endif
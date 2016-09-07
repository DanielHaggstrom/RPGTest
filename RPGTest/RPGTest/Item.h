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

	void increase() { HowMany++; }
	void decrease() { HowMany--; }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

#endif
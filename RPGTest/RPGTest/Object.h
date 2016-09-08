#ifndef OBJECT
#define OBJECT

#include <string>
#include <fstream>

struct Object
{
	std::string id;

	std::string getId() { return id; }

	bool load(std::ifstream &file);
	void save(std::ofstream &file);
};

#endif
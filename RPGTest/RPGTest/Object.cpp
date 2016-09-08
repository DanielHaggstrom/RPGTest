#include "Object.h"

bool Object::load(std::ifstream &file)
{
	file >> id;

	return !file.fail();
}

void Object::save(std::ofstream &file)
{
	file << id << std::endl;
}
#include <fstream>
#include <iostream>
#include "quest.h"

//NUNCA NUNCA UTILIZAR LAS BIBLIOTECA IOSTREAM EN UN 
//ARCHIVO QUE NO SEA EL ESPCIFICO PARA LA INTERFAZ

//TEMPORAL
//"quest.txt"
//leer/escribir
//descripciones


Quest::Quest()
{
    id = "DEFAULT";
    description = "DEFAULT";
    avaiable = false;
    completed = false;
}
Quest::Quest(const std::string id)
{
    this->id = id;
	description = "template";
    avaiable = false;
    completed = false;
}
Quest::~Quest()
{
}

void Quest::printQuest()
{
    std::cout << "Quest name: " << id << std::endl;
    std::cout << "Quest description: " << description << std::endl << std::endl << std::endl;
}


bool Quest::load(std::ifstream &file)
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

void Quest::save(std::ofstream &file)
{
	file << id << " " << HowMany << std::endl;
}


#include <fstream>
#include <iostream>
#include <string>
#include "quest.h"
#include "archivo.h"

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
	description = find(id, "quest.txt");
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

void Quest::readQuest(){
	description = find(id, "quest.txt");
}

void Quest::save()
{
	std::fstream file("quest.txt", std::ios::out | std::ios::app);
	file << this->id << std::endl;
	file << this->description << std::endl;
	file << std::endl;
	file.close();
}



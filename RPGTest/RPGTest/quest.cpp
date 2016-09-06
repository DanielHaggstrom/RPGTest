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
	fisnished = false;
}
Quest::Quest(const std::string id)
{
    this->id = id;
	description = find(id, "quest.txt");
    avaiable = false;
    completed = false;
	fisnished = false;
}
Quest::~Quest()
{
}

void Quest::printQuest()
{
    std::cout << "Quest name: " << id << std::endl;
	std::cout << "Quest description: " << description << std::endl;
	std::cout << "Avaiable: " << avaiable << std::endl;
	std::cout << "Completed: " << completed << std::endl;
	std::cout << "Finshed: " << fisnished << std::endl << std::endl << std::endl;
}

void Quest::readQuest(){
	description = find(id, "quest.txt");
}

void Quest::loadQuest(){//EXCEPCION ARCHIVO NO SE PUEDE ABRIR

	std::string aux_avaiable;
	std::string aux_completed;
	std::string aux_finished;

	description = find(id, "quest.txt");

	//READ AVAIABLE
	aux_avaiable = find("avaiable_Quest", "Jugador1.txt");

	if (aux_avaiable == this->id){
		this->avaiable = true;
	}

	//READ COMPLETED
	aux_completed = find("completed_Quest", "Jugador1.txt");

	if (aux_completed == this->id){
		this->completed = true;
	}

	//READ FINISHED
	aux_finished = find("finished_Quest", "Jugador1.txt");

	if (aux_finished == this->id){
		this->fisnished = true;
	}


}

void Quest::save()		 //EXCEPCION ARCHIVO NO SE PUEDE ABRIR
{						 //USAR ARCHIVO.H
					     //ASEGURAR BORRAR CAMPO

	std::fstream file("Jugador1.txt", std::ios::in | std::ios::out);
	std::string aux = "";
	//WRITE AVAIABLE
	while (file.getline(aux))
	{
		if (aux == "avaiable_Quest"){

			file.seekg(0, std::ios::cur);//ASEGURAR BORRAR CAMPO
			file << this->id;
			file.seekg(file.tellg(), std::ios::beg);

		}
	}
	//WRITE COMPLETED

	//WRITE FINISHED
	file << this->id << std::endl;
	file << this->description << std::endl;
	file << this->avaiable << std::endl;
	file << this->completed << std::endl;
	file << std::endl;
	file.close();*/
}

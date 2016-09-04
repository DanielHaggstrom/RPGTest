#include "quest.h"
#include <iostream>


int main()
{
	Quest prueba;


	prueba.setId("Paco");
	prueba.setDescription("whacha doing?");

	prueba.printQuest();

	prueba.save();

	std::cin.ignore();
	return 0;
}

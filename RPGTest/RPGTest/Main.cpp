#include "quest.h"
#include <iostream>


int main()
{
	Quest prueba1;
	Quest prueba2;
	Quest prueba3;
	Quest prueba4;

	prueba1.setId("q_bandidos");
	prueba2.setId("q_veneno");
	prueba3.setId("q_bandidos2");
	prueba4.setId("q_bandidos3");

	prueba1.printQuest();
	prueba2.printQuest();
	prueba3.printQuest();
	prueba4.printQuest();

	prueba1.loadQuest();
	prueba2.loadQuest();
	prueba3.loadQuest();
	prueba4.loadQuest();

	prueba1.printQuest();
	prueba2.printQuest();
	prueba3.printQuest();
	prueba4.printQuest();

	std::cin.ignore();
	return 0;
}

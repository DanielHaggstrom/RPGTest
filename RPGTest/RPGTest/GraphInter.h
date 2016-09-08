#ifndef GRAPHINTER
#define GRAPHINTER

#include "GameList.h"
#include "quest.h"
#include <string>
#include <vector>

/*----------------------------
Class responsible for interacting with the user
through the console
------------------------------*/

class GraphInter
{
private:

	static GraphInter* inter;
	
	GraphInter() {}

	int update(int key, int elem, int max_elems);

	int menu(std::vector<std::string> elems, std::string statement);

	void tab_word(std::string word, int pos, int cont);
	std::string tab_word(std::string word);

public:

	static GraphInter* get();
	static void close();
	static void load();

	int mainMenu(GameList games);

	std::string linea();
	void clearConsole();
	void pause();

	std::string valid_user();

	std::string center_word(std::string word, int length, std::string arround);

	int QuestMenu(Quest quest);

	void enter(std::string &word);
	void enter(int &digit);
	void enter(char* str);

	void display(std::string error);
	void display(char sign);
};
#endif
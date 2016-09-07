#include "GlobalConstants.h"
#include "GraphInter.h"
#include "utilsWin.h"
#include <iostream>
#include <ctype.h>
#include <sstream>
#include <iomanip>
#include <conio.h>
#include <vector>

GraphInter* GraphInter::inter = nullptr;

GraphInter* GraphInter::get() { return inter; }

void GraphInter::close()
{
	if (inter != nullptr) delete inter;
}

void GraphInter::load()
{
	if (inter == nullptr) inter = new GraphInter;
}

int GraphInter::mainMenu()
{
	std::vector<std::string> elems;

	elems.push_back("Sign up");
	elems.push_back("Sign in");
	elems.push_back("Exit");

	return menu(elems);
}

void GraphInter::pause()
{
	std::cin.sync();
	std::cin.get();
}

void GraphInter::clearConsole() { system("cls"); }

std::string GraphInter::valid_user()
{
	std::ostringstream character;
	std::string id;
	bool id_right;

	do
	{
		clearConsole();
		id_right = true;

		display("Enter your id: ");
		enter(id);

		if (id.size() > 15)
		{
			message("Error, your id cannot be longer than 15 characters ");

			id_right = false;
		}
		else
		{
			for (char i : id)
			{
				if ('A' > i || i > 'Z' && i < 'a' || i > 'z')
				{
					message("Error, your id cannot contain symbols or numbers, only leters");

					id_right = false;
				}
				else i = tolower(i);
			}
		}
	} while (!id_right);

	id = id + "@fdimail.com";

	return id;
}

void GraphInter::enter(std::string &word)
{
	std::cin.sync();
	std::getline(std::cin, word);
	std::cin.clear();
}

void GraphInter::enter(int &digit)
{
	std::cin.sync();
	std::cin >> digit;
	std::cin.clear();
}

void GraphInter::enter(char* str)
{
	std::cin.sync();
	std::cin >> str;
	std::cin.clear();
}

void GraphInter::display(std::string error)
{
	std::cout << error << std::endl;
}

void GraphInter::display(char sign)
{
	std::cout << sign;
}

int GraphInter::update(int key, int elem, int max_elems)
{
	if (key == UP) elem--;
	if (key == DOWN) elem++;

	if (elem < 0) elem = max_elems - 1;
	if (elem >= max_elems) elem = 0;

	if (key == ESCAPE) elem = max_elems - 1;
	return elem;
}

std::string GraphInter::linea()
{
	std::ostringstream line;

	line << std::setfill('-')
		<< std::setw(HORIZONTAL) << '-'
		<< std::setfill(' ');

	return line.str();
}

int GraphInter::menu(std::vector<std::string> elems)
{
	int key = UP, elem = 0;

	do
	{
		display("Which one do you choose?: ");

		for (int i = 0; i < elems.size(); i++)
		{
			tab_word(elems[i], i, elem);
		}

		key = getKey();
		elem = update(key, elem, elems.size());

		clearConsole();

	} while (key != ENTER && key != ESCAPE);

	return elem;
}

void GraphInter::tab_word(std::string word, int pos, int cont)
{
	if (pos == cont) word = "->" + word;

	else word = tab_word(word);

	display(word);
}

std::string GraphInter::tab_word(std::string word)
{
	std::ostringstream tab;

	tab << std::setw(word.size() + 2) << word;

	return tab.str();
}
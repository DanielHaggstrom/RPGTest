#ifndef ITEMLIST
#define ITEMLIST

#include "MainList.h"
#include <fstream>
#include "Item.h"

class ItemList : public List<Item> 
{
public:

	bool load(std::ifstream & file)
	{
		int n;
		Item* newItem;

		file >> n;

		if (!file.fail())
		{
			for (int i = 0; i < n; i++)
			{
				newItem = new Item;

				if (!newItem->load(file))
				{
					delete newItem;
					return false;
				}
				else insert(newItem);
			}
			return true;
		}
		else return false;
	}

	void save(std::ofstream &file)
	{
		file << counter << std::endl;

		for (int i = 0; i < counter; i++)
		{
			list[i]->save(file);
		}
	}
};

#endif
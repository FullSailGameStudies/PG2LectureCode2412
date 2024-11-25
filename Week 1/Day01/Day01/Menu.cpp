#include "Menu.h"
#include "Console.h"

//DEFINITION:
//	actual code for the method block

void Menu::AddMenuItem(std::string itemToAdd)
{
	//add the parameter to the _items vector
	_items.push_back(itemToAdd);
}

void Menu::Show()
{
	Console::WriteLine("\nPG2 Cafe (range-based loop)", ConsoleColor::Cyan);
	//range-based for loop
	for (std::string& item : _items)
	{
		Console::WriteLine(item, ConsoleColor::Yellow);
	}

	Console::WriteLine("\nPG2 Cafe (for loop)", ConsoleColor::Cyan);
	for (int i = 0; i < _items.size(); i++)
	{
		Console::WriteLine( _items.at(i), ConsoleColor::Yellow);
	}

	Console::WriteLine("\nPG2 Cafe (iterator for loop)", ConsoleColor::Cyan);
	for (std::vector<std::string>::iterator i = _items.begin();i != _items.end();i++)
	{
		//use the iterator like a pointer
		//use * to dereference the iterator (go to the item it "points" to)
		std::string item = *i;
		Console::WriteLine(item, ConsoleColor::Yellow);
	}
}

bool Menu::RemoveMenuItem(std::string itemToRemove)
{
	bool wasRemoved = false;
	//erase with an iterator loop
	for (auto i = _items.begin(); i != _items.end(); i++)
	{
		//_stricmp
		int compResult = _stricmp(itemToRemove.c_str(), i->c_str());
		// compResult < 0  LESS THAN
		// compResult == 0  EQUAL TO
		// compResult > 0   GREATER THAN
		if (compResult == 0) 
		{
			_items.erase(i);
			wasRemoved = true;
			break;//exits the loop
		}
	}

	//erase with a for loop
	for (int i = 0; i < _items.size(); i++)
	{
		int compResult = _stricmp(itemToRemove.c_str(), _items[i].c_str());
		if (compResult == 0) //itemToRemove == _items[i])
		{
			_items.erase(_items.begin() + i);
			return true;
		}
	}
	return wasRemoved;
}

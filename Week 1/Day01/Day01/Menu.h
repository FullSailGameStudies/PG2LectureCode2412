#pragma once
#include <vector>
#include <string>
class Menu
{
public:
	//DECLARATION
	// describes how to communicate to the block
	// 
	//add an item to the menu
	void AddMenuItem(std::string itemToAdd);

	//add a method to show the menu items
	void Show();

	//method to remove a menu item
	bool RemoveMenuItem(std::string itemToRemove);

private:
	std::vector<std::string> _items;
};


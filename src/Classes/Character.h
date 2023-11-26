//
// Created by ajivaji on 11/16/2023.
//

#pragma once

#include <string>
#include <vector>
#include "Objects/Object.h"
#include "Objects/Item.h"

namespace WG {
class Character {
public:

	void setName(const std::string &name);
	std::string getName();
	std::vector<Item *> getInventory();
	void addItem(Item *item);
	void removeItem(Item *item);
	bool hasItem(Item* item);

private:
	std::string characterName;
	std::vector<Item *> inventoryItems;


};

}
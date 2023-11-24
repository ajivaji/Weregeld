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
	std::vector<Item *> getInventoryObjects();
	void addInventoryObject(Item *item);
	void removeInventoryObject(Item *item);
	void hasObject(const std::string &objectName, Object *&outObject);

private:
	std::string characterName;
	std::vector<Item *> inventoryObjects;


};

}
//
// Created by ajivaji on 11/16/2023.
//

#include <algorithm>
#include "Character.h"

namespace WG {
void Character::setName(const std::string &name) {
	characterName = name;
}

std::string Character::getName() {
	return characterName;
}

std::vector<Item *> Character::getInventory() {
	return inventoryItems;
}

void Character::addItem(Item *item) {
	inventoryItems.push_back(item);
}

void Character::removeItem(Item *item) {
	for (auto &inventoryObject: inventoryItems) {
		if (inventoryObject == item) {
			inventoryItems.erase(std::remove(inventoryItems.begin(), inventoryItems.end(), item),
			                     inventoryItems.end());
			break;
		}
	}
}

bool Character::hasItem(Item* item) {
	for (const auto &inventoryObject : inventoryItems) {
		if (inventoryObject == item) {
			return true;
		}
	}
	return false;
}

}
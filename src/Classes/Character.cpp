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

std::vector<Item *> Character::getInventoryObjects() {
	return inventoryObjects;
}

void Character::addInventoryObject(Item *item) {
	inventoryObjects.push_back(item);
}

void Character::removeInventoryObject(Item *item) {
	for (auto &inventoryObject: inventoryObjects) {
		if (inventoryObject == item) {
			inventoryObjects.erase(std::remove(inventoryObjects.begin(), inventoryObjects.end(), item),
			                       inventoryObjects.end());
			break;
		}
	}
}

void Character::hasObject(const std::string &objectName, Object* &outObject) {
	for (const auto &object: inventoryObjects) {
		auto objectNamelower = object->getObjectName();
		std::transform(objectNamelower.begin(), objectNamelower.end(), objectNamelower.begin(), ::tolower);
		if (objectName == objectNamelower) {
			outObject = object;
			return;
		}
	}
}

}
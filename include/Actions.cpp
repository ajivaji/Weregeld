//
// Created by ajivaji on 11/18/2023.
//



#include <string>
#include <iostream>
#include "GameData.h"
#include "Objects/Location.h"
#include "Game.h"
#include "Objects/Door.h"

namespace WG {
void doGo(gameData *data, Object* object, Object* indirectObject) {
	auto location = dynamic_cast<Location *>(object);
	auto door = dynamic_cast<Door *>(object);
	if(door == nullptr && location == nullptr) {
		std::cout << "You can't go there!" << std::endl;
		return;
	}
	if(location != nullptr) {
		if(data->currentLocation == location) {
			std::cout << "You are already there!" << std::endl;
			return;
		}
		if(!data->currentLocation->hasConnection(location)) {
			std::cout << "You can't go there!" << std::endl;
			return;
		}

		Game::getInstance().setLocation(location);
		std::cout << "You went to " << location->getSubjectName() << std::endl;
		return;
	}
	if(door != nullptr) {
		if(door->isLocked()) {
			std::cout << "The door is locked!" << std::endl;
			return;
		}
		auto location1 = door->getLocation1();
		auto location2 = door->getLocation2();
		if(data->currentLocation == location1) {
			Game::getInstance().setLocation(location2);
			std::cout << "You went to " << location2->getSubjectName() << std::endl;
		}
		if(data->currentLocation == location2) {
			Game::getInstance().setLocation(location1);
			std::cout << "You went to " << location1->getSubjectName() << std::endl;
		}
		std::cout << "You can't go there!" << std::endl;
		return;
	}
}

void doLook(gameData *data, Object* object, Object* indirectObject) {
//	if(objectName == "around") {
//		std::cout << data->currentLocation->getObjectDescription() << std::endl;
//		return;
//	}
//	if(!data->currentLocation->hasItem(objectName)) {
//		std::cout << "You don't see that here!" << std::endl;
//		return;
//	}
//	std::cout << data->currentLocation->getObject(objectName)->getObjectDescription() << std::endl;
}

void doTake(gameData *data, Object* object = nullptr, Object* indirectObject = nullptr) {
    auto item = dynamic_cast<Item *>(object);
    if(item == nullptr) {
        std::cout << "You don't see that here!" << std::endl;
        return;
    }
	if(data->player->hasItem(item)) {
		std::cout << "You already have that!" << std::endl;
		return;
	}
	data->player->addItem(item);
	data->currentLocation->removeItem(item);
}

void doDrop(gameData *data, Object* object = nullptr, Object* indirectObject = nullptr) {
	//add picked up items to the local objects vector so that they can be dropped
	auto item = dynamic_cast<Item *>(object);
	if(item == nullptr) {
		std::cout << "You can't drop that!" << std::endl;
		return;
	}
	if(!data->player->hasItem(item)) {
		std::cout << "You don't have that!" << std::endl;
		return;
	}
	data->currentLocation->addItem(item);
	data->player->removeItem(item);
	std::cout << "You dropped " << item->getObjectName() << std::endl;
	std::cout << "New inventory size: " << data->player->getInventory().size() << std::endl;
}

void doInventory(gameData *data, Object* object = nullptr, Object* indirectObject = nullptr) {
	std::cout << "You have the following items:" << std::endl;
	if(data->player->getInventory().empty()) {
		std::cout << "Nothing" << std::endl;
		return;
	}
	for(auto &item : data->player->getInventory()) {
		std::cout << item->getObjectName() << std::endl;
	}
}

void doUse(gameData *data, Object* object = nullptr, Object* indirectObject = nullptr) {
	auto item = dynamic_cast<Item *>(object);
	if(item == nullptr) {
		std::cout << "You can't use that!" << std::endl;
		return;
	}
	if(!data->player->hasItem(item)) {
		std::cout << "You don't have that!" << std::endl;
		return;
	}

	std::cout << "You can't use that!" << std::endl;
}
}
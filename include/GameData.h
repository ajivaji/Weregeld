//
// Created by ajivaji on 11/18/2023.
//

#pragma once

#include "Objects/Location.h"
#include "Objects/Item.h"
#include "Character.h"
#include <iostream>

namespace WG {
struct gameData {
	typedef void (*action)(gameData *, Object*, Object*);

	Character *player{};
	Location *currentLocation{};
	std::vector<Object*> localObjects;
	std::vector<Object*> globalObjects;
	std::map<std::string, std::vector<std::map<std::string, std::vector<std::string>>>> actionObjectIndirectObjectMap;
	//          action name,                      object name,       indirect object name
	std::map<std::string, action> actions;

	std::map<int, Object*> IDObjectMap;

	void addObjectID(Object* object) {
		if(IDObjectMap.find(object->getObjectID()) != IDObjectMap.end()) {
			std::cout << "Duplicate ID found: " << object->getObjectName() << ": " << object->getObjectID() << std::endl;
			exit(1);
		}
		IDObjectMap[object->getObjectID()] = object;
	}
};
}
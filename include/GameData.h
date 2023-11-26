//
// Created by ajivaji on 11/18/2023.
//

#pragma once

#include "Objects/Location.h"
#include "Objects/Item.h"
#include "Character.h"

namespace WG {
struct gameData {
	typedef void (*action)(gameData *, Object*, Object*);

	Character *player{};
	Location *currentLocation{};
	std::vector<Object*> localObjects;
	std::vector<Item*> items;
	std::vector<Location*> locations;
	std::map<std::string, std::vector<std::map<std::string, std::vector<std::string>>>> actionObjectIndirectObjectMap;
	//          action name,                      object name,       indirect object name
	std::map<std::string, action> actions;
};
}
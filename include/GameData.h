//
// Created by ajivaji on 11/18/2023.
//

#pragma once

#include <vector>
#include <string>
#include <map>
#include "Character.h"
#include "Location.h"
#include "Actions.h"

struct gameData {
	typedef void (*action)(const std::string&, gameData*);
	Location* currentLocation{};
	std::vector<Location*> locations;
	std::map<std::string, std::vector<std::string>> actionActionablesmap;
	std::map<std::string, action> actions;
};
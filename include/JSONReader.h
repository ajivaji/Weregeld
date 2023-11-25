//
// Created by ajivaji on 11/18/2023.
//

#pragma once

#include <fstream>
#include "../external/nlohmann-json/json.hpp"
#include "Objects/Location.h"
#include "GameData.h"


namespace WG {
	void readLocationsJSONFile(gameData *data);
	void readLocationFromJSON(std::stringstream &locationStream, gameData *data);
	std::string writeLocationJSONString(Location *location);
	void writeLocationsJSONFile(gameData *data);

	void writeItemsJSONFile(gameData *data);
	std::string writeItemJSONString(Item *item);
	void readItemsJSONFile(gameData *data);
	void readItemFromJSON(std::stringstream &itemStream, gameData *data);
}
//
// Created by ajivaji on 11/18/2023.
//

#pragma once

#include <fstream>
#include "../external/nlohmann-json/json.hpp"
#include "Objects/Location.h"
#include "GameData.h"
#include "Objects/Door.h"


namespace WG {

void writeObjectsJSONFile(gameData *data);

void readObjectsJSONFile(gameData *data);

std::string itemtoJSON(Item* item);

std::string locationtoJSON(Location* location);

std::string doortoJSON(Door* door);

std::string keytoJSON(Key* key);
}
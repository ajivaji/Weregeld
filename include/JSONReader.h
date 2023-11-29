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
void readLocationsJSONFile(gameData *data);
void readLocationFromJSON(std::stringstream &locationStream, gameData *data);
void writeLocationsJSONFile(gameData *data);

void writeItemsJSONFile(gameData *data);
void readItemsJSONFile(gameData *data);
void readItemFromJSON(std::stringstream &itemStream, gameData *data);

void writeObjectsJSONFile(gameData *data);

std::string itemtoJSON(Item* item);

std::string locationtoJSON(Location* location);

std::string doortoJSON(Door* door);

std::string keytoJSON(Key* key);
}
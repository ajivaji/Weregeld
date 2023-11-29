//
// Created by ajivaji on 11/19/2023.
//

#include <iostream>
#include "JSONReader.h"
#include "Objects/Location.h"
#include "Objects/Door.h"

namespace WG {
/*
void readLocationsJSONFile(gameData *data) {
	std::string locationsFilePath = "../resources/locations.json";
	std::ifstream locationsFile(locationsFilePath);
	if (!locationsFile.is_open()) {
		std::cout << "Error opening file " << locationsFilePath << std::endl;
		return;
	}
	std::string lineString;
	std::stringstream line;
	while (std::getline(locationsFile, lineString)) {
		line << lineString;
		readLocationFromJSON(line, data);
		lineString = "";
		line.clear();
	}

}

void readLocationFromJSON(std::stringstream &locationStream, gameData *data) {
	auto locationJSON = nlohmann::json::parse(locationStream);

	int locationID = locationJSON["locationID"];
	std::vector<int> connectedIDs = locationJSON["connectedLocationsIDs"];
	std::string locationName = locationJSON["locationName"];
	std::string subjectName = locationJSON["subjectName"];
	std::string locationDescription = locationJSON["locationDescription"];
	std::vector<int> localItemsIDs = locationJSON["localItemsIDs"];

	auto location = new Location(locationID, connectedIDs, locationName, subjectName, locationDescription, localItemsIDs);
	data->locations.push_back(location);
}

void writeLocationsJSONFile(gameData *data) {
	std::string locationsFilePath = "../resources/locations.json";
	std::ofstream locationsFile(locationsFilePath);
	if (!locationsFile.is_open()) {
		std::cout << "Error opening file " << locationsFilePath << std::endl;
		return;
	}
	for (auto &location: data->locations) {
		locationsFile << location->toJSON() << std::endl;
	}
}

void writeItemsJSONFile(gameData *data) {
	std::string objectsFilePath = "../resources/items.json";
	std::ofstream objectsFile(objectsFilePath);
	if (!objectsFile.is_open()) {
		std::cout << "Error opening file " << objectsFilePath << std::endl;
		return;
	}
	for (auto &object: data->items) {
		objectsFile << object->toJSON() << std::endl;
	}
}

void readItemsJSONFile(gameData *data) {
	std::string itemsFilePath = "../resources/items.json";
	std::ifstream itemsFile(itemsFilePath);
	if (!itemsFile.is_open()) {
		std::cout << "Error opening file " << itemsFilePath << std::endl;
		return;
	}
	std::string lineString;
	std::stringstream line;
	while (std::getline(itemsFile, lineString)) {
		line << lineString;
		readItemFromJSON(line, data);
		lineString = "";
		line.clear();
	}
}
void readItemFromJSON(std::stringstream &itemStream, gameData *data) {
	auto itemJSON = nlohmann::json::parse(itemStream);

	int itemID = itemJSON["itemID"];
	std::string itemName = itemJSON["itemName"];
	std::string subjectName = itemJSON["subjectName"];
	std::string itemDescription = itemJSON["itemDescription"];

	auto item = new Item(itemID, itemName, itemDescription, subjectName);
	data->items.push_back(item);
}
*/


void writeObjectsJSONFile(gameData *data) {
	std::string objectsFilePath = "../resources/objects.json";
	std::ofstream objectsFile(objectsFilePath);
	std::string objectString;
	if (!objectsFile.is_open()) {
		std::cout << "Error opening file " << objectsFilePath << std::endl;
		return;
	}
	for (auto &object: data->globalObjects) {
		if(object->getObjectType() == objectType::item) {
			objectString = itemtoJSON(dynamic_cast<Item *>(object));
		}
		else if(object->getObjectType() == objectType::location) {
			objectString = locationtoJSON(dynamic_cast<Location *>(object));
		}
		else if(object->getObjectType() == objectType::door) {
			objectString = doortoJSON(dynamic_cast<Door *>(object));
		}
		else if(object->getObjectType() == objectType::key) {
			objectString = keytoJSON(dynamic_cast<Key *>(object));
		}
		else {
			std::cout << "Error writing object to JSON file: " << object->getObjectName() << ": " << object->getObjectID() << std::endl;
			continue;
		}
		objectsFile << objectString << std::endl;
	}
}

std::string itemtoJSON(Item* item) {
	nlohmann::ordered_json itemJSON;
	itemJSON["type"] = "item";
	itemJSON["itemName"] = item->getObjectName();
	itemJSON["itemDescription"] = item->getObjectDescription();
	itemJSON["subjectName"] = item->getSubjectName();
	itemJSON["itemID"] = item->getObjectID();
	return itemJSON.dump(4);
}

std::string locationtoJSON(Location* location) {
	nlohmann::ordered_json locationJSON;
	locationJSON["type"] = "location";
	locationJSON["locationName"] = location->getObjectName();
	locationJSON["locationDescription"] = location->getObjectDescription();
	locationJSON["subjectName"] = location->getSubjectName();
	locationJSON["locationID"] = location->getObjectID();
	locationJSON["connectedLocationsIDs"] = location->getConnectedLocationsIDs();
	locationJSON["localItemsIDs"] = location->getLocalItemsIDs();
	return locationJSON.dump(4);
}

std::string doortoJSON(Door* door) {
	nlohmann::ordered_json doorJSON;
	doorJSON["type"] = "door";
	doorJSON["doorName"] = door->getObjectName();
	doorJSON["doorDescription"] = door->getObjectDescription();
	doorJSON["subjectName"] = door->getSubjectName();
	doorJSON["doorID"] = door->getObjectID();
	doorJSON["location1ID"] = door->getLocation1()->getObjectID();
	doorJSON["location2ID"] = door->getLocation2()->getObjectID();
	doorJSON["keyID"] = door->getLockID();
	doorJSON["lockedStatus"] = door->isLocked();
	return doorJSON.dump(4);
}
std::string keytoJSON(Key* key) {
	nlohmann::ordered_json keyJSON;
	keyJSON["type"] = "item";
	keyJSON["itemName"] = key->getObjectName();
	keyJSON["itemDescription"] = key->getObjectDescription();
	keyJSON["subjectName"] = key->getSubjectName();
	keyJSON["itemID"] = key->getObjectID();
	keyJSON["keyID"] = key->getKeyID();
	return keyJSON.dump(4);
}
}
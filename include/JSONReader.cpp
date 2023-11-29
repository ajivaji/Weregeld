//
// Created by ajivaji on 11/19/2023.
//

#include <iostream>
#include "JSONReader.h"
#include "Objects/Location.h"
#include "Objects/Door.h"

namespace WG {

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

void readObjectsJSONFile(gameData *data) {
	std::string objectsFilePath = "../resources/objects.json";
	std::ifstream objectsFile(objectsFilePath);
	if (!objectsFile.is_open()) {
		std::cout << "Error opening file " << objectsFilePath << std::endl;
		return;
	}
	nlohmann::json objectsJSON;
	objectsFile >> objectsJSON;
	for(const auto& object : objectsJSON) {
		if(object["type"] == "item") {
			Item* item = new Item(object["objectID"], object["itemName"], object["itemDescription"], object["subjectName"]);
			data->globalObjects.push_back(item);
		}
		else if(object["type"] == "location") {
			Location* location = new Location(object["objectID"], object["locationName"], object["locationDescription"], object["subjectName"], object["connectedLocationsIDs"], object["localItemsIDs"]);
			data->globalObjects.push_back(location);
		}
		else if(object["type"] == "door") {
			Door* door = new Door(object["objectID"], object["doorName"], object["doorDescription"], object["subjectName"], object["location1ID"], object["location2ID"], object["keyCode"], object["lockedStatus"]);
			data->globalObjects.push_back(door);
		}
		else if(object["type"] == "key") {
			Key* key = new Key(object["objectID"], object["itemName"], object["itemDescription"], object["subjectName"], object["keyCode"]);
			data->globalObjects.push_back(key);
		}
		else {
			std::cout << "Error reading object from JSON file: " << object["itemName"] << ": " << object["objectID"] << std::endl;
			continue;
		}
	}
}

std::string itemtoJSON(Item* item) {
	nlohmann::ordered_json itemJSON;
	itemJSON["type"] = "item";
	itemJSON["itemName"] = item->getObjectName();
	itemJSON["itemDescription"] = item->getObjectDescription();
	itemJSON["subjectName"] = item->getSubjectName();
	itemJSON["objectID"] = item->getObjectID();
	return itemJSON.dump(4);
}

std::string locationtoJSON(Location* location) {
	nlohmann::ordered_json locationJSON;
	locationJSON["type"] = "location";
	locationJSON["locationName"] = location->getObjectName();
	locationJSON["locationDescription"] = location->getObjectDescription();
	locationJSON["subjectName"] = location->getSubjectName();
	locationJSON["objectID"] = location->getObjectID();
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
	doorJSON["objectID"] = door->getObjectID();
	doorJSON["location1ID"] = door->getLocation1ID();
	doorJSON["location2ID"] = door->getLocation2ID();
	doorJSON["keyCode"] = door->getkeyCode();
	doorJSON["lockedStatus"] = door->isLocked();
	return doorJSON.dump(4);
}
std::string keytoJSON(Key* key) {
	nlohmann::ordered_json keyJSON;
	keyJSON["type"] = "item";
	keyJSON["keyName"] = key->getObjectName();
	keyJSON["keyDescription"] = key->getObjectDescription();
	keyJSON["subjectName"] = key->getSubjectName();
	keyJSON["objectID"] = key->getObjectID();
	keyJSON["keyCode"] = key->getkeyCode();
	return keyJSON.dump(4);
}
}
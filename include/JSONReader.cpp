//
// Created by ajivaji on 11/19/2023.
//

#include <iostream>
#include "JSONReader.h"
#include "Objects/Location.h"

namespace WG {
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

	std::string writeLocationJSONString(Location *location) {
		nlohmann::json locationJSON;
		locationJSON["locationName"] = location->getObjectName();
		locationJSON["locationDescription"] = location->getObjectDescription();
		locationJSON["subjectName"] = location->getSubjectName();
		locationJSON["locationID"] = location->getObjectID();
		locationJSON["connectedLocationsIDs"] = location->getConnectedLocationsIDs();
		locationJSON["localItemsIDs"] = location->getLocalItemsIDs();
		//locationJSON["actionObjectIndirectObjectMap"] = location->getActionActionablesmap();

		return locationJSON.dump();
	}

	void writeLocationsJSONFile(gameData *data) {
		std::string locationsFilePath = "../resources/locations.json";
		std::ofstream locationsFile(locationsFilePath);
		if (!locationsFile.is_open()) {
			std::cout << "Error opening file " << locationsFilePath << std::endl;
			return;
		}
		for (auto &location: data->locations) {
			locationsFile << writeLocationJSONString(location) << std::endl;
		}
	}

	void writeItemsJSONFile(gameData *data) {
		std::string objectsFilePath = "../resources/objects.json";
		std::ofstream objectsFile(objectsFilePath);
		if (!objectsFile.is_open()) {
			std::cout << "Error opening file " << objectsFilePath << std::endl;
			return;
		}
		for (auto &object: data->items) {
			objectsFile << writeItemJSONString(object) << std::endl;
		}
	}

	std::string writeItemJSONString(Item *item) {
		nlohmann::json objectJSON;
		objectJSON["itemName"] = item->getObjectName();
		objectJSON["itemDescription"] = item->getObjectDescription();
		objectJSON["subjectName"] = item->getSubjectName();
		objectJSON["itemID"] = item->getObjectID();
		return objectJSON.dump();
	}

	void readItemsJSONFile(gameData *data) {
		std::string itemsFilePath = "../resources/objects.json";
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
}
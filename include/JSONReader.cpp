//
// Created by ajivaji on 11/19/2023.
//

#include <iostream>
#include "JSONReader.h"
#include "../src/Classes/Location.h"

namespace WG {
	void readLocationsJSONFile(gameData *data) {
		std::string locationsFilePath = "../resources/locations.json";
		std::ifstream locationsFile(locationsFilePath);
		if(!locationsFile.is_open()) {
			std::cout << "Error opening file " << locationsFilePath << std::endl;
			return;
		}
		std::string lineString;
		std::stringstream line;
		while(std::getline(locationsFile, lineString)) {
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

		auto location = new Location(locationID, connectedIDs, locationName, subjectName, locationDescription);
		data->locations.push_back(location);
	}

	std::string writeLocationJSONString(Location *location) {
		nlohmann::json locationJSON;
		locationJSON["locationName"] = location->getLocationName();
		locationJSON["locationDescription"] = location->getLocationDescription();
		locationJSON["subjectName"] = location->getSubjectName();
		locationJSON["locationID"] = location->getLocationID();
		locationJSON["connectedLocationsIDs"] = location->getConnectedLocationsIDs();
		//locationJSON["actionActionablesmap"] = location->getActionActionablesmap();

		return locationJSON.dump();
	}

	void writeLocationsJSONFile(gameData *data) {
		std::string locationsFilePath = "../resources/locationstest.json";
		std::ofstream locationsFile(locationsFilePath);
		if(!locationsFile.is_open()) {
			std::cout << "Error opening file " << locationsFilePath << std::endl;
			return;
		}
		for(auto &location : data->locations) {
			locationsFile << writeLocationJSONString(location) << std::endl;
		}
	}
}
//
// Created by ajivaji on 11/16/2023.
//

#include "Location.h"

std::string Location::getLocationName() {
	return locationName;
}

std::string Location::getSubjectName() {
	return subjectName;
}

bool Location::hasConnection(const std::string &locationName) {
	for(auto &location : connectedLocations) {
		if(location->getLocationName() == locationName) {
			return true;
		}
	}
	return false;
}

Location *Location::getConnection(const std::string &locationName) {
	for(auto &location : connectedLocations) {
		if(location->getLocationName() == locationName) {
			return location;
		}
	}
	return nullptr;
}

void Location::connectLocation(Location *location) {
	connectedLocations.push_back(location);
	connectedLocationsIDs.push_back(location->getLocationID());
}

void Location::disconnectLocation(Location *location) {

}

int Location::getLocationID() {
	return locationID;
}

std::string Location::getLocationDescription() {
	return locationDescription;
}

std::vector<int> Location::getConnectedLocationsIDs() {
	return connectedLocationsIDs;
}

Location::Location(int locationID, std::vector<int> connectedIDs, std::string locationName, std::string subjectName, std::string locationDescription) {
	this->locationID = locationID;
	this->connectedLocationsIDs = connectedIDs;
	this->locationName = locationName;
	this->subjectName = subjectName;
	this->locationDescription = locationDescription;
}

/*std::map<std::string, std::vector<std::string>> Location::getActionActionablesmap() {
	return actionActionablesmap;
}*/

//
// Created by ajivaji on 11/16/2023.
//

#include <algorithm>
#include <utility>
#include "Location.h"

namespace WG {

bool Location::hasConnection(Object *queriedLocation) {
	queriedLocation = dynamic_cast<Location *>(queriedLocation);
	if(queriedLocation == nullptr) {
		return false;
	}
	for (const auto &object: objects) {
		if (object == queriedLocation) {
			return true;
		}
	}
	return false;
}

Location *Location::getConnection(const std::string &locationName) {
	for (auto &location: connectedLocations) {
		if (location->getObjectName() == locationName) {
			return location;
		}
	}
	return nullptr;
}

void Location::connectLocation(Location *location) {
	objects.push_back(location);
	if (std::find(connectedLocationsIDs.begin(), connectedLocationsIDs.end(), location->getObjectID()) ==
	    connectedLocationsIDs.end()) {
		connectedLocationsIDs.push_back(location->getObjectID());
	}
}

void Location::disconnectLocation(Location *location) {

}

std::vector<int> Location::getConnectedLocationsIDs() {
	return connectedLocationsIDs;
}

Location::Location(int locationID, std::vector<int> connectedIDs, std::string locationName, std::string subjectName,
                   std::string locationDescription)
				   : Object(locationID,
							std::move(locationName),
							std::move(locationDescription),
							std::move(subjectName)) {
	this->connectedLocationsIDs = std::move(connectedIDs);
}

std::vector<Object *> Location::getObjects() {
	return objects;
}

bool Location::hasObject(const std::string &objectName, Object* &outObject) {
	for (const auto &object: objects) {
		auto objectNamelower = object->getObjectName();
		std::transform(objectNamelower.begin(), objectNamelower.end(), objectNamelower.begin(), ::tolower);
		if (objectName == objectNamelower) {
			outObject = object;
			return true;
		}
	}
}

	Object *Location::getObject(const std::string &basicString) {
		return nullptr;
	}

}
/*std::map<std::string, std::vector<std::string>> Location::getActionActionablesmap() {
	return actionObjectIndirectObjectMap;
}*/

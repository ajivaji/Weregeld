//
// Created by ajivaji on 11/16/2023.
//

#include <algorithm>
#include <utility>
#include "Location.h"
#include "../../../external/nlohmann-json/json.hpp"

namespace WG {

bool Location::hasConnection(Location *queriedLocation) {
	for (const auto &location: connectedLocations) {
		if (location == queriedLocation) {
			return true;
		}
	}
	return false;
}

void Location::connectLocation(Location *location) {
	connectedLocations.push_back(location);
	objects.push_back(location);
//	if (std::find(connectedLocationsIDs.begin(), connectedLocationsIDs.end(), location->getObjectID()) ==
//	    connectedLocationsIDs.end()) {
//		connectedLocationsIDs.push_back(location->getObjectID());
//	}
}

void Location::disconnectLocation(Location *location) {

}

std::vector<int> Location::getConnectedLocationsIDs() {
	return connectedLocationsIDs;
}

Location::Location(int locationID, std::vector<int> connectedIDs, std::string locationName, std::string subjectName,
                   std::string locationDescription, std::vector<int> localItemsIDs)
				   : Object(locationID,
							std::move(locationName),
							std::move(locationDescription),
							std::move(subjectName)) {
	this->connectedLocationsIDs = std::move(connectedIDs);
	this->localItemsIDs = std::move(localItemsIDs);
	this->type = objectType::location;
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
	return false;
}


	Object *Location::getObject(const std::string &basicString) {
		return nullptr;
	}

	bool Location::hasItem(Item *queriedItem) {
		for (const auto &item : localItems) {
			if (item == queriedItem) {
				return true;
			}
		}
		return false;
	}

	std::vector<int> Location::getLocalItemsIDs() {
		return localItemsIDs;
	}

	void Location::addItem(Item *item) {
		localItems.push_back(item);
	}

	void Location::removeItem(Item *item) {
		for (auto &inventoryObject: localItems) {
			if (inventoryObject == item) {
				localItems.erase(std::remove(localItems.begin(), localItems.end(), item),
				                 localItems.end());
				break;
			}
		}

	}

	std::vector<Item *> Location::getLocalItems() {
		return localItems;
	}

	std::vector<Location *> Location::getConnectedLocations() {
		return connectedLocations;
	}



}
/*std::map<std::string, std::vector<std::string>> Location::getActionActionablesmap() {
	return actionObjectIndirectObjectMap;
}*/

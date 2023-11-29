//
// Created by ajivaji on 11/16/2023.
//

#include <algorithm>
#include <utility>
#include "Location.h"
#include "../../../external/nlohmann-json/json.hpp"

namespace WG {

Location::Location(int objectID, std::string locationName, std::string subjectName,
                   std::string locationDescription, std::vector<int> objectIDs)
		: Object(objectID,
		         std::move(locationName),
		         std::move(locationDescription),
		         std::move(subjectName)) {
	this->type = objectType::location;
	this->objectsIDs = std::move(objectIDs);
}

bool Location::hasConnection(Location *queriedLocation) {
	for (const auto &location: objects) {
		if (location == queriedLocation) {
			return true;
		}
	}
	return false;
}

void Location::connectLocation(Location *location) {
	objects.push_back(location);
}

void Location::disconnectLocation(Location *location) {

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

void Location::addObject(Object *object) {
	objects.push_back(object);
}

void Location::removeObject(Object *object) {
	for (auto &object1: objects) {
		if (object1 == object) {
			objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
			break;
		}
	}

}

std::vector<Object *> Location::getObjects() {
	return objects;
}

bool Location::hasItem(Item *queriedItem) {
	return false;
}

std::vector<int> Location::getObjectIDs() {
	return objectsIDs;
}


}
/*std::map<std::string, std::vector<std::string>> Location::getActionActionablesmap() {
	return actionObjectIndirectObjectMap;
}*/

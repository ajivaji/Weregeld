//
// Created by ajivaji on 11/16/2023.
//

#pragma once

#include <string>
#include <vector>
#include <map>
#include "Object.h"
#include "Item.h"

namespace WG {
class Location : public Object {
public:
	Location(int objectID, std::string locationName,
	         std::string locationDescription, std::string subjectName, std::vector<int> objectIDs);

	bool hasConnection(Location *queriedLocation);

	void connectLocation(Location *location);

	void disconnectLocation(Location *location);

	bool hasObject(const std::string &objectName, Object *&outObject);

    bool hasItem(Item* queriedItem);

	Object *getObject(const std::string &basicString);

	void addObject(Object *object);

	void removeObject(Object *object);

	std::vector<Object *> getObjects();

	std::vector<int> getObjectIDs();

private:

	std::vector<int> objectsIDs;
	std::vector<Object *> objects;
	//std::map<std::string, std::vector<std::string>> actionObjectIndirectObjectMap;
};

}
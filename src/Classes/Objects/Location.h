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
	Location(int locationID, std::vector<int> connectedIDs, std::string locationName, std::string subjectName,
	         std::string locationDescription);

	bool hasConnection(Location *queriedLocation);

	void connectLocation(Location *location);

	void disconnectLocation(Location *location);

	std::vector<int> getConnectedLocationsIDs();

	bool hasObject(const std::string &objectName, Object *&outObject);

    bool hasItem(Item* queriedItem);

	std::vector<int> getLocalItemsIDs();

	Object *getObject(const std::string &basicString);

	void addItem(Item *item);

	void removeItem(Item *item);

private:
	std::vector<int> connectedLocationsIDs;
	std::vector<Location*> connectedLocations;
    std::vector<Item*> localItems;
	std::vector<int> localItemsIDs;

	std::vector<Object *> objects;
	//std::map<std::string, std::vector<std::string>> actionObjectIndirectObjectMap;
};

}
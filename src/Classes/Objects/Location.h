//
// Created by ajivaji on 11/16/2023.
//

#pragma once

#include <string>
#include <vector>
#include <map>
#include "Object.h"

namespace WG {
class Location : public Object {
public:
	Location(int locationID, std::vector<int> connectedIDs, std::string locationName, std::string subjectName,
	         std::string locationDescription);

	bool hasConnection(Object *queriedLocation);

	Location *getConnection(const std::string &basicString);

	void connectLocation(Location *location);

	void disconnectLocation(Location *location);

	std::vector<int> getConnectedLocationsIDs();

	std::vector<Object *> getObjects();

	bool hasObject(const std::string &objectName, Object *&outObject);

	Object *getObject(const std::string &basicString);

private:
	std::vector<Location *> connectedLocations;
	std::vector<int> connectedLocationsIDs;

	std::vector<Object *> objects;
	std::vector<int> objectIDs;
	//std::map<std::string, std::vector<std::string>> actionObjectIndirectObjectMap;
};

}
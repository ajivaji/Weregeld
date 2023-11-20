//
// Created by ajivaji on 11/16/2023.
//

#pragma once

#include <string>
#include <vector>
#include <map>

class Location {
public:
	Location(int locationID, std::vector<int> connectedIDs, std::string locationName, std::string subjectName, std::string locationDescription);

	std::string getLocationName();

	std::string getSubjectName();

	bool hasConnection(const std::string &basicString);

	Location *getConnection(const std::string &basicString);

	void connectLocation(Location* location);

	void disconnectLocation(Location* location);

	int getLocationID();

	std::string getLocationDescription();

	std::vector<int> getConnectedLocationsIDs();

	//std::map<std::string, std::vector<std::string>> getActionActionablesmap();

private:
	std::vector<Location*> connectedLocations;
	std::vector<int> connectedLocationsIDs;
	int locationID;
	std::string locationName;
	std::string locationDescription;
	std::string subjectName;
	//std::map<std::string, std::vector<std::string>> actionActionablesmap;
};

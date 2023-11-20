//
// Created by ajivaji on 11/18/2023.
//



#include <string>
#include <iostream>
#include <cassert>
#include "GameData.h"
#include "Location.h"

namespace WG {
	void doGo(const std::string &locationName, gameData *data) {
		if(data->currentLocation->getLocationName() == locationName) {
			std::cout << "You are already there!" << std::endl;
			return;
		}
		if(!data->currentLocation->hasConnection(locationName)) {
			std::cout << "You can't go there!" << std::endl;
			return;
		}
		Location* newLocation = data->currentLocation->getConnection(locationName);
		assert(newLocation != nullptr);
		data->currentLocation = newLocation;
		std::cout << "You went to " << newLocation->getSubjectName() << std::endl;
	}

	void doLook(const std::string &objectName, gameData *data) {

	}

	void doTake(const std::string &objectName, gameData *data) {

	}

	void doDrop(const std::string &objectName, gameData *data) {

	}

	void doInventory(const std::string &objectName, gameData *data) {

	}
}
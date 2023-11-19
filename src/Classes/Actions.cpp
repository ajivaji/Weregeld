//
// Created by ajivaji on 11/18/2023.
//
#include "Actions.h"

namespace WG {
	void doGo(const std::string &locationName, gameData *data) {
		/*if(!data->currentLocation->hasConnection(locationName)) {
			std::cout << "You can't go there!" << std::endl;
			return;
		}
		Location* newLocation = data->currentLocation.getConnection(locationName);
		data->currentLocation = newLocation;
		std::cout << "You went to " << newLocation.getSubjectName() << std::endl;*/
		if(locationName == "north") {
			std::cout << "You went north" << std::endl;
		}
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
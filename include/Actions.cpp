//
// Created by ajivaji on 11/18/2023.
//



#include <string>
#include <iostream>
#include <cassert>
#include "GameData.h"
#include "Objects/Location.h"

namespace WG {
	void doGo(gameData *data, Object* object, Object* indirectObject) {
		auto location = dynamic_cast<Location *>(object);
		if(location == nullptr) {
			std::cout << "You can't go there!" << std::endl;
			return;
		}
		if(data->currentLocation == location) {
			std::cout << "You are already there!" << std::endl;
			return;
		}
		if(!data->currentLocation->hasConnection(location)) {
			std::cout << "You can't go there!" << std::endl;
			return;
		}
		data->currentLocation = location;
		std::cout << "You went to " << location->getSubjectName() << std::endl;
	}

	void doLook(gameData *data, Object* object, Object* indirectObject) {
//		if(objectName == "around") {
//			std::cout << data->currentLocation->getObjectDescription() << std::endl;
//			return;
//		}
//		if(!data->currentLocation->hasObject(objectName)) {
//			std::cout << "You don't see that here!" << std::endl;
//			return;
//		}
//		std::cout << data->currentLocation->getObject(objectName)->getObjectDescription() << std::endl;
	}

	void doTake(gameData *data, Object* object = nullptr, Object* indirectObject = nullptr) {

	}

	void doDrop(gameData *data, Object* object = nullptr, Object* indirectObject = nullptr) {

	}

	void doInventory(gameData *data, Object* object = nullptr, Object* indirectObject = nullptr) {

	}
}
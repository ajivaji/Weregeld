//
// Created by ajivaji on 11/27/2023.
//

#include "Door.h"
#include "../../../external/nlohmann-json/json.hpp"


namespace WG {


int Door::getkeyCode() const {
	return keyCode;
}

bool Door::isLocked() const {
	return lockedStatus;
}

void Door::lockUnlock(const Key &key) {
	if(key.getkeyCode() == getkeyCode()){
		lockedStatus = !lockedStatus;
	}
}

Location *Door::getLocation1() const {
	return location1;
}

Location *Door::getLocation2() const {
	return location2;
}


}
//
// Created by ajivaji on 11/27/2023.
//

#include "Door.h"
#include "../../../external/nlohmann-json/json.hpp"


namespace WG {


int Door::getLockID() const {
	return lockID;
}

bool Door::isLocked() const {
	return lockedStatus;
}

void Door::lockUnlock(const Key &key) {
	if(key.getKeyID() == getLockID()){
		lockedStatus = !lockedStatus;
	}
}

Location *Door::getLocation1() const {
	return location1;
}

Location *Door::getLocation2() const {
	return location2;
}

std::string Door::toJSON() {
	nlohmann::json doorJSON;
	doorJSON["doorName"] = this->getObjectName();
	doorJSON["doorDescription"] = this->getObjectDescription();
	doorJSON["subjectName"] = this->getSubjectName();
	doorJSON["doorID"] = this->getObjectID();
	doorJSON["location1ID"] = this->getLocation1()->getObjectID();
	doorJSON["location2ID"] = this->getLocation2()->getObjectID();
	doorJSON["keyID"] = this->getLockID();
	doorJSON["lockedStatus"] = this->isLocked();
	return doorJSON.dump();
}
}
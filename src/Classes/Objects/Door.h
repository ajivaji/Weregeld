//
// Created by ajivaji on 11/27/2023.
//

#pragma once

#include <utility>

#include "Interfaces/Unlockable.h"
#include "Location.h"

namespace WG {
class Door : public Unlockable, public Object {

public:
	Door(const int &objectId, std::string objectName, std::string objectDescription, std::string subjectName,
	     Location *location1, Location *location2, int keyID, bool lockedStatus)
		 : Object(objectId, std::move(objectName), std::move(objectDescription), std::move(subjectName)),
		 location1(location1), location2(location2), Unlockable(keyID, lockedStatus) {};

	int getLockID() const override;

	bool isLocked() const override;

	void lockUnlock(const Key &key) override;

	Location* getLocation1() const;

	Location* getLocation2() const;

	std::string toJSON();

private:
	Location* location1;
	Location* location2;
};
}
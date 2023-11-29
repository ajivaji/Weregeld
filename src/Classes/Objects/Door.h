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
	     int location1ID, int location2ID, int keyCode, bool lockedStatus)
		 : Object(objectId, std::move(objectName), std::move(objectDescription), std::move(subjectName)),
		 location1ID(location1ID), location2ID(location2ID), Unlockable(keyCode, lockedStatus){
		this->type = objectType::door;
	};

	int getkeyCode() const override;

	bool isLocked() const override;

	void lockUnlock(const Key &key) override;

	Location* getLocation1() const;

	Location* getLocation2() const;

private:
	Location* location1;
	Location* location2;
};
}
//
// Created by ajivaji on 11/27/2023.
//

#pragma once


#include "Objects/Items/Key.h"

namespace WG {
class Unlockable {
	Unlockable(int keyID, bool lockedStatus) : keyID(keyID), lockedStatus(lockedStatus) {};

	virtual int getKeyID() const = 0;

	virtual bool isLocked() const = 0;

	virtual void unlock(const Key& key) = 0;
private:
	int keyID;
	bool lockedStatus;
};

}
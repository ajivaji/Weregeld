//
// Created by ajivaji on 11/27/2023.
//

#pragma once


#include "Objects/Items/Key.h"

namespace WG {
class Unlockable {
public:
	Unlockable(int keyCode, bool lockedStatus) : keyCode(keyCode), lockedStatus(lockedStatus) {};

	virtual int getkeyCode() const = 0;

	virtual bool isLocked() const = 0;

	virtual void lockUnlock(const Key& key) = 0;

protected:
	bool lockedStatus;
	int keyCode;
};

}
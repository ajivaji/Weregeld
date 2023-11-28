//
// Created by ajivaji on 11/27/2023.
//

#include "Key.h"

#include <utility>

namespace WG {
Key::Key(const int &objectID, std::string objectName, std::string objectDescription, std::string subjectName, int keyID)
		: Item(objectID, std::move(objectName), std::move(objectDescription), std::move(subjectName)) {
	this->keyID = keyID;
}

Key::Key(const Key& key) : Item(key.objectID, key.objectName, key.objectDescription, key.subjectName) {

}

int Key::getKeyID() const {
	return keyID;
}

}
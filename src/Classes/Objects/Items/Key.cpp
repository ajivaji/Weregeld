//
// Created by ajivaji on 11/27/2023.
//

#include "Key.h"

#include <utility>

namespace WG {
Key::Key(const int &objectID, std::string objectName, std::string objectDescription, std::string subjectName, int keyCode)
		: Item(objectID, std::move(objectName), std::move(objectDescription), std::move(subjectName)) {
	this->keyCode = keyCode;
	this->type = objectType::key;
}

Key::Key(const Key& key) : Item(key.objectID, key.objectName, key.objectDescription, key.subjectName) {
	this->keyCode = key.keyCode;
}

int Key::getkeyCode() const {
	return keyCode;
}

}
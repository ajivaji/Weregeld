//
// Created by ajivaji on 11/20/2023.
//

#include "Object.h"

#include <utility>
namespace WG {
	Object::Object(const int& objectID, std::string objectName, std::string objectDescription, std::string subjectName) {
		this->objectID = objectID;
		this->objectName = std::move(objectName);
		this->objectDescription = std::move(objectDescription);
		this->subjectName = std::move(subjectName);
	}

	int Object::getObjectID() const {
		return objectID;
	}

	std::string Object::getObjectName() {
		return objectName;
	}

	std::string Object::getObjectDescription() {
		return objectDescription;
	}

	std::string Object::getSubjectName() {
		return subjectName;
	}

objectType Object::getObjectType() const {
	return type;
}


//objects should have descriptions that change based on the game state. This function can be overridden by subclasses
	//ex: locations having different descriptions based on where they are viewed from.
	//ex: doors being described as either closed, or leading to a location, depending on whether or not it is locked.
//	std::string Object::getContextualDescription(gameData *gameData) {
//		std::string contextualDescription = objectDescription;
//
//
//		return contextualDescription;
//	}
}
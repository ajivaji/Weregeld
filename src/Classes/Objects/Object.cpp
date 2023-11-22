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

	int Object::getObjectID() {
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
}
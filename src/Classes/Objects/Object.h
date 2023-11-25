//
// Created by ajivaji on 11/20/2023.
//

#pragma once


#include <string>

namespace WG {
class Object {
public:
	Object(const int& objectID, std::string objectName, std::string objectDescription, std::string subjectName);

	int getObjectID();

	std::string getObjectName();

	std::string getObjectDescription();

	std::string getSubjectName();

	virtual ~Object() = default;

protected:
	int objectID;
	std::string objectName;
	std::string objectDescription;
	std::string subjectName;
};

}

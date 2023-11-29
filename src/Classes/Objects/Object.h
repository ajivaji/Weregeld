//
// Created by ajivaji on 11/20/2023.
//

#pragma once


#include <string>

namespace WG {

enum objectType {
	location,
	door,
	item,
	key
};

struct gameData;
class Object {
public:
	Object(const int& objectID, std::string objectName, std::string objectDescription, std::string subjectName);

	int getObjectID() const;

	std::string getObjectName();

	std::string getObjectDescription();

	std::string getSubjectName();

	objectType getObjectType() const;

	//virtual std::string getContextualDescription(gameData* gameData);

	virtual ~Object() = default;

protected:
	int objectID;
	std::string objectName;
	std::string objectDescription;
	std::string subjectName;
	objectType type{};
};

}

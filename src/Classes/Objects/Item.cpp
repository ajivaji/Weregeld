//
// Created by ajivaji on 11/20/2023.
//

#include "Item.h"

#include <utility>
#include <iostream>

namespace WG {
Item::Item(const int &objectID, std::string objectName, std::string objectDescription, std::string subjectName)
		: Object(objectID, std::move(objectName), std::move(objectDescription), std::move(subjectName)) {
	printf("Item %s created\n", this->getObjectName().c_str());
}

Item::Item(const int &objectId, std::string objectName, std::string objectDescription, std::string subjectName,
           const Item &) : Object(objectId, std::move(objectName), std::move(objectDescription), std::move(subjectName)) {
	printf("Item %s copied\n", this->getObjectName().c_str());


}

}
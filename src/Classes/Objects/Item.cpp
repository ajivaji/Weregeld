//
// Created by ajivaji on 11/20/2023.
//

#include "Item.h"
#include "../../../external/nlohmann-json/json.hpp"

#include <utility>
#include <iostream>

namespace WG {
Item::Item(const int &objectID, std::string objectName, std::string objectDescription, std::string subjectName)
		: Object(objectID, std::move(objectName), std::move(objectDescription), std::move(subjectName)) {
	printf("Item %s created\n", this->getObjectName().c_str());
}

Item::Item(const Item& item) : Object(item.objectID, item.objectName, item.objectDescription, item.subjectName) {

}

std::string Item::toJSON() {
	nlohmann::json objectJSON;
	objectJSON["itemName"] = this->getObjectName();
	objectJSON["itemDescription"] = this->getObjectDescription();
	objectJSON["subjectName"] = this->getSubjectName();
	objectJSON["itemID"] = this->getObjectID();
	return objectJSON.dump();
}

}
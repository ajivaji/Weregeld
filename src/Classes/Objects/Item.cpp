//
// Created by ajivaji on 11/20/2023.
//

#include "Item.h"

#include <utility>
#include <iostream>

namespace WG {
Item::Item(const int &objectID, std::string objectName, std::string objectDescription, std::string subjectName)
		: Object(objectID, std::move(objectName), std::move(objectDescription), std::move(subjectName)) {

}

}
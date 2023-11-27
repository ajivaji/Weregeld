//
// Created by ajivaji on 11/20/2023.
//

#pragma once

#include "Object.h"

namespace WG {
class Item : public Object {
public:
	Item(const int& objectID, std::string objectName, std::string objectDescription, std::string subjectName);
	Item(const int &objectId, std::string objectName, std::string objectDescription, std::string subjectName,
	     const Item &);

private:

};

}
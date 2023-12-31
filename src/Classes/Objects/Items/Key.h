//
// Created by ajivaji on 11/27/2023.
//

#pragma once

#include "../Item.h"

namespace WG {
class Key : public Item {
public:
	Key(const int& objectID, std::string objectName, std::string objectDescription, std::string subjectName, int keyCode);
	Key(const Key& key);

	int getkeyCode() const;
private:
	int keyCode;
};

}
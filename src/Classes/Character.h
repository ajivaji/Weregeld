//
// Created by ajivaji on 11/16/2023.
//

#pragma once

#include <string>
#include "Location.h"

class Character {
public:
	Character() {
		initCharacter();
	}

	void initCharacter() {

	}

	void setName(const std::string& name);
private:
	std::string characterName;
};

//
// Created by ajivaji on 11/16/2023.
//

#pragma once

#include <string>


namespace WG {

	struct gameData;

	void doGo(const std::string &locationName, gameData *data);

	void doLook(const std::string &objectName, gameData *data);

	void doTake(const std::string &objectName, gameData *data);

	void doDrop(const std::string &objectName, gameData *data);

	void doInventory(const std::string &objectName, gameData *data);
}
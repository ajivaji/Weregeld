//
// Created by ajivaji on 11/18/2023.
//

#pragma once


#include <vector>
#include <string>
#include "../../include/GameData.h"

namespace WG {

class Game {

public:

	static Game& getInstance() {
		static Game instance;
		return instance;
	}

	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	void initGame();

	static std::vector<std::string> getInput(std::string &userInput);

	void doAction(std::vector<std::string> &inputArgs);

	void playGame();

	void updateLocalObjects();

	bool objectIsPresent(std::string &objectName, Object* &outObject);

	void setLocation(Location *location);

private:

	Game() = default;

	~Game();

	gameData* _gameData;
};

}
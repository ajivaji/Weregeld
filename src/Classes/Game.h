//
// Created by ajivaji on 11/18/2023.
//

#pragma once


#include <vector>
#include <string>
#include "Character.h"
#include "../../include/GameData.h"

namespace WG {

	class Game {
public:
	Game();

	void initGame();

	std::vector<std::string> getInput(std::string &userInput);

	void doAction(std::vector<std::string> &inputArgs);

	void playGame();

	~Game();

private:
	Character player;
	gameData* _gameData;
};

}
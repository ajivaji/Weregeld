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

	void doAction(const std::vector<std::string> &inputArgs, const std::vector<std::string> &actionableNames);

	void startGame();

	~Game();

private:
	Character player;
	gameData* _gameData;
};

}
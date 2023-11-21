//
// Created by ajivaji on 11/18/2023.
//
#include <algorithm>
#include <iostream>
#include "Game.h"
#include "../../include/Actions.h"
#include "../../include/JSONReader.h"

namespace WG {

	typedef void (*action)(const std::string&, gameData*);
	void doGo(const std::string &locationName, gameData *data);
	void doLook(const std::string &objectName, gameData *data);
	void doTake(const std::string &objectName, gameData *data);
	void doDrop(const std::string &objectName, gameData *data);
	void doInventory(const std::string &objectName, gameData *data);

	Game::Game() {
		initGame();
	}

	void Game::initGame() {
		std::string userInput;
		std::cout << "Welcome to the game!" << std::endl;
		std::cout << "What is your name?" << std::endl;
		std::getline(std::cin, userInput);
		player.setName(userInput);
		_gameData = new gameData;

		/*_gameData->actionActionablesmap = {
				{"go",        {"north", "south", "east", "west"}},
				{"look",      {"north", "south", "east", "west", "around"}},
				{"take",      {"item1", "item2", "item3"}},
				{"drop",      {"item1", "item2", "item3"}},
				{"inventory", {}},
				{"quit",      {}}
		};*/

		_gameData->actions = {
				{"go",        &doGo},
				{"look",      &doLook},
				//{"inspect"},  &doInspect},
				{"take",      &doTake},
				{"drop",      &doDrop},
				{"inventory", &doInventory}
		};

		readLocationsJSONFile(_gameData);
		for (auto &location : _gameData->locations) {
			for (auto &locationID : location->getConnectedLocationsIDs()) {
				location->connectLocation(_gameData->locations[locationID - 1]);
			}
		}
		_gameData->currentLocation = _gameData->locations[0];

	}

	std::vector<std::string> Game::getInput(std::string &userInput) {
		std::vector<std::string> inputArguments;
		std::cout << "What would you like to do?" << std::endl;
		std::getline(std::cin, userInput);
		while (userInput.find(' ') != std::string::npos) {
			inputArguments.push_back(userInput.substr(0, userInput.find(' ')));
			userInput.erase(0, userInput.find(' ') + 1);
		}
		inputArguments.push_back(userInput);
		return inputArguments;
	}

	void Game::doAction(const std::vector<std::string> &inputArgs, const std::vector<std::string> &actionableNames) {
		if (!actionableNames.empty()) {
			if (std::find(actionableNames.begin(), actionableNames.end(), inputArgs[1]) == actionableNames.end()) {
				std::cout << "You can't do that." << std::endl;
				return;
			}
		}
		std::cout << "You did it!" << std::endl;
		_gameData->actions[inputArgs[0]](inputArgs[1], _gameData);

	}

	void Game::startGame() {
		std::string userInput;
		while (userInput != "quit") {
			std::vector<std::string> inputArguments = getInput(userInput);
			if (inputArguments[0] == "quit") {
				std::cout << "Are you sure you want to quit?" << std::endl;
				std::cout << "Y/N" << std::endl;
				std::getline(std::cin, userInput);
				userInput = std::toupper(userInput[0]);
				if (userInput == "Y") {
					std::cout << "Goodbye!" << std::endl;
					return;
				} else {
					continue;
				}
			}
			if (inputArguments.empty() || inputArguments.size() > 2) {
				std::cout << "Invalid input. Try again." << std::endl;
				continue;
			}
			//actions[actionArgument](inputArguments[1], actionActionablesmap[actionArgument]);
			doAction(inputArguments, _gameData->actionActionablesmap[inputArguments[0]]);
		}
	}

	Game::~Game() {
		//add loops which delete all the locations and such.
		delete _gameData;
	}
}
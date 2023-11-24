//
// Created by ajivaji on 11/18/2023.
//
#include <algorithm>
#include <iostream>
#include "Game.h"
#include "../../include/Actions.h"
#include "../../include/JSONReader.h"

namespace WG {

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

	/*_gameData->actionObjectIndirectObjectMap = {
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

	auto item = new Item(1, "Paper", "A piece of paper.", "the paper");
	_gameData->items.push_back(item);
	writeItemsJSONFile(_gameData);

	_gameData->currentLocation = _gameData->locations[0];

}

std::vector<std::string> Game::getInput(std::string &userInput) {
	std::vector<std::string> inputArguments;
	std::cout << "What would you like to do?" << std::endl;
	std::getline(std::cin, userInput);
	while (userInput.find(' ') != std::string::npos) {
		std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
		inputArguments.push_back(userInput.substr(0, userInput.find(' ')));
		userInput.erase(0, userInput.find(' ') + 1);
	}
	std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);
	inputArguments.push_back(userInput);
	return inputArguments;
}

void Game::doAction(std::vector<std::string> &inputArgs) {

	//keep a vector of objects in the current location
	//each object has a map<string, vector<string>> for each action and indirect object

	bool foundObject = false;
	Object* object = nullptr;
	Object* indirObject = nullptr;

	if(std::find(inputArgs.begin(), inputArgs.end(), "inventory") != inputArgs.end()) {
		inputArgs[0] = "inventory";
		_gameData->actions[inputArgs[0]](_gameData, object, indirObject);
	}

	if (_gameData->actions.find(inputArgs[0]) == _gameData->actions.end()) {
		std::cout << "You can't do that." << std::endl;
		return;
	}

	int foundObjectIndex = -1;
	if(inputArgs.size() > 1) {
		for (int i = 1; i < inputArgs.size(); i++) {
			if (_gameData->currentLocation->hasObject(inputArgs[i], object)) {
				foundObject = true;
				foundObjectIndex = i;
				break;
			}
		}
	}
	if(foundObject && inputArgs.size() > 2) {
		for (int i = foundObjectIndex + 1; i < inputArgs.size(); i++) {
			if (_gameData->currentLocation->hasObject(inputArgs[i], indirObject)) {
				if(indirObject == object) {
					std::cout << "You can't do that." << std::endl;
					return;
				}
				break;
			}
		}
	}

	//std::cout << "You did it!" << std::endl;
	_gameData->actions[inputArgs[0]](_gameData, object, indirObject);

}

void Game::playGame() {
	std::string userInput;
	while (userInput != "quit") {
		std::vector<std::string> inputArguments = getInput(userInput);
		if (inputArguments.empty()) {
			std::cout << "Invalid input. Try again." << std::endl;
			continue;
		}
		if (inputArguments[0] == "quit") {
			std::cout << "Are you sure you want to quit?" << std::endl;
			std::cout << "Y/N" << std::endl;
			std::getline(std::cin, userInput);
			userInput = std::toupper(userInput[0]);
			if (userInput == "Y") {
				std::cout << "Goodbye!" << std::endl;
				return;
				//to be neat, add a function which deletes all the locations and such.
			}
			continue;
		}
		//actions[actionArgument](inputArguments[1], actionObjectIndirectObjectMap[actionArgument]);
		doAction(inputArguments);
	}
}

Game::~Game() {
	//add loops which delete all the locations and such.
	delete _gameData;
}
}
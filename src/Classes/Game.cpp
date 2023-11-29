//
// Created by ajivaji on 11/18/2023.
//
#include <algorithm>
#include <iostream>
#include "Game.h"
#include "../../include/Actions.h"
#include "../../include/JSONReader.h"
#include "Objects/Door.h"

namespace WG {


void Game::initGame() {
	_gameData = new gameData;
	std::string userInput;
	std::cout << "Welcome to the game!" << std::endl;
	std::cout << "What is your name?" << std::endl;
	std::getline(std::cin, userInput);
	auto player = new Character;
	_gameData->player = player;
	_gameData->player->setName(userInput);

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
			{"use",       &doUse},
			{"take",      &doTake},
			{"drop",      &doDrop},
			{"inventory", &doInventory}
	};





	Location *location1 = new Location(0, "Location1", "This is location 1. Testing",
									   "location1", std::vector<int>{1, 100});
	Location *location2 = new Location(1, "Location2","This is location 2.",
									   "location2", std::vector<int>{0, 200});
	Location *location3 = new Location(2, "Location3","This is location 3.",
									   "location3", std::vector<int>{200});
	_gameData->globalObjects.push_back(location1);
	_gameData->globalObjects.push_back(location2);
	_gameData->globalObjects.push_back(location3);

	Door *door = new Door(200, "Door", "This is a door.", "door", 2, 3, 123, true);
	_gameData->globalObjects.push_back(door);
	Key *key = new Key(100, "Key", "This is a key.", "key", 123);
	_gameData->globalObjects.push_back(key);
	//fill map with objects and IDs
	for(auto &object : _gameData->globalObjects) {
		_gameData->addObjectID(object);
	}

	for(auto &object : _gameData->globalObjects) {
		if(object->getObjectType() == objectType::location) {
			auto location = dynamic_cast<Location*>(object);
			for(const auto &objectID : location->getObjectIDs()) {
				location->addObject(_gameData->IDObjectMap[objectID]);
			}
		}
	}

	writeObjectsJSONFile(_gameData);

	Game::getInstance().setLocation(dynamic_cast<Location*>(_gameData->globalObjects[0]));

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

	if (_gameData->actions.find(inputArgs[0]) == _gameData->actions.end()) {
		std::cout << "You can't do that." << std::endl;
		return;
	}

	int foundObjectIndex = -1;
	if(inputArgs.size() > 1) {
		for (int i = 1; i < inputArgs.size(); i++) {
			if (objectIsPresent(inputArgs[i], object)) {
				foundObject = true;
				foundObjectIndex = i;
				break;
			}
		}
	}
	if(foundObject && inputArgs.size() > 2) {
		for (int i = foundObjectIndex + 1; i < inputArgs.size(); i++) {
			if (objectIsPresent(inputArgs[i], indirObject)) {
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

void Game::updateLocalObjects() {
	_gameData->localObjects.clear();
	for(auto &item : _gameData->player->getInventory()) {
		_gameData->localObjects.push_back(item);
	}
	for(auto &object : _gameData->currentLocation->getObjects()) {
		_gameData->localObjects.push_back(object);
	}
}

Game::~Game() {
	//add loops which delete all the locations and such.
	delete _gameData;
}

bool Game::objectIsPresent(std::string &objectName, Object *&outObject) {
	for (const auto &object : _gameData->localObjects) {
		auto objectNamelower = object->getObjectName();
		std::transform(objectNamelower.begin(), objectNamelower.end(), objectNamelower.begin(), ::tolower);
		if (objectName == objectNamelower) {
			outObject = object;
			return true;
		}
	}
	return false;
}

	void Game::setLocation(Location *location) {
		_gameData->currentLocation = location;
		updateLocalObjects();
	}

}
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include "Actions.h"
#include "Character.h"


typedef void (*action)(const std::string&);


namespace WG {

class Game {
public:
	Game() {
		initGame();
	}

	void initGame() {
		std::string userInput;
		std::cout << "Welcome to the game!" << std::endl;
		std::cout << "What is your name?" << std::endl;
		std::getline(std::cin, userInput);
		player.setName(userInput);
		//in the future, this will be replaced with a file reader that will read in the locations from a file and create them with their own maps
		//the actionActionablesmap and actions map will be read in from the current location
		actionActionablesmap = {
			{"go", {"north", "south", "east", "west"}},
			{"look", {"north", "south", "east", "west", "around"}},
			{"take", {"item1", "item2", "item3"}},
			{"drop", {"item1", "item2", "item3"}},
			{"inventory", {}},
			{"quit", {}}
		};

		action goAction = doGo;
		action lookAction = doLook;
		action takeAction = doTake;
		action dropAction = doDrop;
		action inventoryAction = doInventory;

		actions = {
			{"go", goAction},
			{"look", lookAction},
			{"take", takeAction},
			{"drop", dropAction},
			{"inventory", inventoryAction}
		};

	}

	std::vector<std::string> getInput(std::string &userInput) {
		std::vector<std::string> inputArguments;
		std::cout << "What would you like to do?" << std::endl;
		std::getline(std::cin, userInput);
		while(userInput.find(' ') != std::string::npos) {
			inputArguments.push_back(userInput.substr(0, userInput.find(' ')));
			userInput.erase(0, userInput.find(' ') + 1);
		}
		inputArguments.push_back(userInput);
		return inputArguments;
	}

	void doAction(const std::vector<std::string>& inputArgs, const std::vector<std::string>& actionableNames) {
		if (!actionableNames.empty()) {
			if (std::find(actionableNames.begin(), actionableNames.end(), inputArgs[1]) == actionableNames.end()) {
				std::cout << "You can't do that." << std::endl;
				return;
			}
		}
		std::cout << "You did it!" << std::endl;
		actions[inputArgs[0]](inputArgs[1]);

	}

	void startGame() {
		std::string userInput;
		while(userInput != "quit") {
			std::vector<std::string> inputArguments;
			inputArguments = getInput(userInput);
			if(inputArguments[0] == "quit") {
				std::cout << "Are you sure you want to quit?" << std::endl;
				std::cout << "Y/N" << std::endl;
				std::getline(std::cin, userInput);
				if (userInput == "Y") {
					std::cout << "Goodbye!" << std::endl;
					return;
				}
				else {
					continue;
				}
			}
			if (inputArguments.empty() || inputArguments.size() > 2) {
				std::cout << "Invalid input. Try again." << std::endl;
				continue;
			}
			if (!(actionActionablesmap.find(inputArguments[0]) != actionActionablesmap.end())) {
				std::cout << "This is not a valid action." << std::endl;
				continue;
			}
			//actions[actionArgument](inputArguments[1], actionActionablesmap[actionArgument]);
			doAction(inputArguments, actionActionablesmap[inputArguments[0]]);
		}
	}

	void changeLocation() {

	}

private:
	Character player;
	std::vector<Location> locations;
	std::map<std::string, std::vector<std::string>> actionActionablesmap;
	std::map<std::string, action> actions;
};

}

int main() {
	WG::Game game;
	game.startGame();

	return 0;
}







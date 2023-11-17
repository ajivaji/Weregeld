#include <vector>
#include <string>
#include <functional>
#include <map>
#include <iostream>
#include "Actions.h"
#include "Character.h"


using action = std::function<void(std::string, std::vector<std::string>)>;


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
		actionActionablesmap = {
			{"go", {"north", "south", "east", "west"}},
			{"look", {"north", "south", "east", "west", "around"}},
			{"take", {"item1", "item2", "item3"}},
			{"drop", {"item1", "item2", "item3"}},
			{"inventory", {}},
			{"quit", {}}
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

	void doAction(const std::string& inputArg, const std::vector<std::string>& actionableNames) {
		if (!actionableNames.empty()) {
			if (std::find(actionableNames.begin(), actionableNames.end(), inputArg) == actionableNames.end()) {
				std::cout << "You can't do that." << std::endl;
				return;
			}
		}
		std::cout << "You did it!" << std::endl;
	}

	void startGame() {
		std::string userInput;
		while(userInput != "quit") {
			std::vector<std::string> inputArguments;
			inputArguments = getInput(userInput);
			if (inputArguments.empty() || inputArguments.size() > 2) {
				std::cout << "Invalid input. Try again." << std::endl;
				continue;
			}
			std::string actionArgument = std::move(inputArguments[0]);
			if (!(actionActionablesmap.find(actionArgument) != actionActionablesmap.end())) {
				std::cout << "This is not a valid action." << std::endl;
				continue;
			}
			//actions[actionArgument](inputArguments[1], actionActionablesmap[actionArgument]);
			doAction(inputArguments[1], actionActionablesmap[actionArgument]);
		}
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







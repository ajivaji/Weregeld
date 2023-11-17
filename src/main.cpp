#include <vector>
#include <string>
#include <functional>
#include <map>
#include <iostream>
#include "Actions.h"
#include "Character.h"


using action = std::function<void(std::string)>;


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
	}

	std::vector<std::string> getInput(std::string &userInput) {
		std::vector<std::string> inputArguments;
		std::cout << "What would you like to do?" << std::endl;
		std::getline(std::cin, userInput);
		//create a loop that iterates through the string, extracting each word without spaces into the vector
		while(userInput.find(' ') != std::string::npos) {
			inputArguments.push_back(userInput.substr(0, userInput.find(' ')));
			userInput.erase(0, userInput.find(' ') + 1);
		}
		inputArguments.push_back(userInput);
		return inputArguments;
	}

	void startGame() {
		std::string userInput;
		while(userInput != "quit") {
			std::vector<std::string> inputArguments;
			inputArguments = getInput(userInput);
			if(inputArguments.empty() || inputArguments.size() > 2) {
				std::cout << "Invalid input. Try again." << std::endl;
				continue;
			}
			if(!(actions.find(inputArguments[0]) != actions.end())) {
				std::cout << "This action is not available. Try again." << std::endl;
				continue;
			}

			actions[inputArguments[0]](inputArguments[1]);
		}
	}

private:
	Character player;
	std::map<std::string, action> actions;
};

}

int main() {
	WG::Game game;
	game.startGame();

	return 0;
}







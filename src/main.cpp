#include "../include/Actions.h"
#include "Game.h"



int main() {
	WG::Game& game = WG::Game::getInstance();
	game.initGame();
	game.playGame();

	return 0;
}
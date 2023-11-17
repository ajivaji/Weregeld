#include <vector>

namespace WG {

	class Game {
	public:
		Game();
		void StartGame();
	private:
		Character player;
};

int main() {
	WG::Game game;
	game.StartGame();

	return 0;
}







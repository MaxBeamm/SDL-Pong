#include "Game.h"

Game* game = nullptr;

int main(int argc, const char* argv[]) {
	
	game = new Game();

	game->init("SDL PONG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}
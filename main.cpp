#include "Game.h"

Game* game = nullptr;

int main(int argc, const char* argv[]) {
	
	game = new Game();

	game->init("SDL PONG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, false);

	const int FPS = 60;
	const int frameDelay = 1000 / FPS; // Milliseconds per frame

	Uint32 frameStart;
	int frameTime;

	while (game->running()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
	return 0;
}
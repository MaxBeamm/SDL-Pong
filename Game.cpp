#include "Game.h"

Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	int flags{ 0 };
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_INIT_EVERYTHING < 0) {
		std::cout << "SDL could not initialize! SDL_ERROR: " << SDL_GetError() << "\n";
		isRunning = false;
	}
	else {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (!window) {
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
		}

		renderer = SDL_CreateRenderer(window, -1, flags);
		if (!renderer) std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << "\n";
		else {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

	
		paddleLeft = new Paddle(5, 20, 40, 150);

		isRunning = true;
	}


}

void Game::render(){

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	paddleLeft->render(renderer);

	SDL_RenderPresent(renderer);

}

void Game::update() {

	paddleLeft->update();

}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
	paddleLeft->handleInput(event);
}

void Game::clean() {
	
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_Quit();

}


#include "Game.h"

Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	windowWidth = width; 
	windowHeight = height;

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

	
		paddleLeft = new Paddle(10, 20, 40, 150, Paddle::Type::LEFT);

		paddleRight = new Paddle(width - 40 - 10, 20, 40, 150, Paddle::Type::RIGHT);
		
		ball = new Ball(width /2, height /2, 10, 10, 5);

		isRunning = true;
	}


}

void Game::render(){

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	paddleLeft->render(renderer);
	paddleRight->render(renderer);

	ball->render(renderer);

	SDL_RenderPresent(renderer);

}

void Game::update() {

	paddleLeft->update();
	paddleRight->update();
	ball->update();

	checkCollisions();

}

void Game::checkCollisions() {
	SDL_Rect ballRect = ball->getRect();
	SDL_Rect paddle1Rect = paddleLeft->getRect();
	SDL_Rect paddle2Rect = paddleRight->getRect();

	std::pair<int, int> currVel = ball->getVelocity();
	
	//Collision with top or bottom of screen
	if (ballRect.y <= 0 || ballRect.y + ballRect.h >= windowHeight) {
		
		ball->setVelocity({ currVel.first, -currVel.second });
	}

	///Collision with left or right of screen
	if (ballRect.x <= 0 || ballRect.x + ballRect.w >= windowWidth) {

		ball->setVelocity({ -currVel.first, currVel.second });
		
	}
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
	paddleRight->handleInput(event);
}

void Game::clean() {
	
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_DestroyRenderer(renderer);
	renderer = nullptr;
	
	paddleLeft = nullptr;
	paddleRight = nullptr;

	SDL_Quit();

}


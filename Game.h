#pragma once
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Paddle.h"
#include "Ball.h"


class Game {

public:

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void clean();
	void handleEvents();
	void checkCollisions();

	bool running() { return isRunning; };

private:

	bool isRunning;
	int windowWidth, windowHeight;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Paddle* paddleLeft;
	Paddle* paddleRight;
	Ball* ball;
};

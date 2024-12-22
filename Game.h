#pragma once
#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "paddle.h"


class Game {

public:

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void clean();
	void handleEvents();

	bool running() { return isRunning; };

private:

	bool isRunning;

	SDL_Window* window;
	SDL_Renderer* renderer;
	Paddle* paddleLeft;
};

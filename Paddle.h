#pragma once
#include <SDL.h>

class Paddle {

	public:

		Paddle(int x, int y, int width, int height);

		enum class Direction {NONE, UP, DOWN};

		void update();
		void render(SDL_Renderer* renderer);
		void handleInput(SDL_Event& Event);

	private:

		int x, y;
		int velocity;
		int speed;
		int width;
		int height;
		Direction direction;


};
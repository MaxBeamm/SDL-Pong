#pragma once
#include <SDL.h>

class Paddle {

	public:

		enum class Type { LEFT, RIGHT };
		enum class Direction { NONE, UP, DOWN };

		Paddle(int x, int y, int width, int height, Type type);

		void update();
		void render(SDL_Renderer* renderer);
		void handleInput(SDL_Event& Event);
		SDL_Rect getRect();

	private:

		int x, y;
		int velocity;
		int speed;
		int width;
		int height;
		Direction direction;
		Type type;


};
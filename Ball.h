#pragma once

#include <SDL.h>
#include <utility>

class Ball {

	public:
		Ball(int x, int y, int width, int height, int speed);

		void update();
		void render(SDL_Renderer* renderer);
		SDL_Rect getRect() const;

		std::pair<int, int> getVelocity() const;
		void setVelocity(std::pair<int, int>);


	private:
		int x, y;
		int xVelocity, yVelocity;
		int width;
		int height;
		
};


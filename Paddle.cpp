#include "Paddle.h"
#include <iostream>

Paddle::Paddle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height), speed(1), velocity(0), direction(Direction::NONE) {}


void Paddle::render(SDL_Renderer* renderer) {

	SDL_Rect paddleRect{ x, y, width, height };
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderFillRect(renderer, &paddleRect);
}

void Paddle::handleInput(SDL_Event& event) {

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym)
		{
			case SDLK_UP:
				this->direction = Direction::UP;
				break;
			case SDLK_DOWN:
				this->direction = Direction::DOWN;
				break;
			default:
				break;
		}
	} 
	else if (event.type == SDL_KEYUP) {
		switch (event.key.keysym.sym)
		{
			case SDLK_UP:
			case SDLK_DOWN:
				this->direction = Direction::NONE;
				break;
			default:
				break;
		}
	}
}

void Paddle::update() {
	
	if (this->direction == Direction::UP) y -= speed;
	else if (this->direction == Direction::DOWN) y += speed;

}
 
#include "Paddle.h"
#include <iostream>

Paddle::Paddle(int x, int y, int width, int height, Type type) : x(x), y(y), width(width), height(height), type(type), speed(8), velocity(0), direction(Direction::NONE) {}


void Paddle::render(SDL_Renderer* renderer) {

	SDL_Rect paddleRect = getRect();
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderFillRect(renderer, &paddleRect);
}

void Paddle::handleInput(SDL_Event& event) {

	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym)
		{
			case SDLK_UP:
				if (this->type == Type::RIGHT) this->direction = Direction::UP;
				break;
			case SDLK_DOWN:
				if (this->type == Type::RIGHT) this->direction = Direction::DOWN;
				break;
			case SDLK_w:
				if (this->type == Type::LEFT) this->direction = Direction::UP;
				break;
			case SDLK_s:
				if (this->type == Type::LEFT) this->direction = Direction::DOWN;
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
			case SDLK_w:
			case SDLK_s:
				this->direction = Direction::NONE;
				break;
			default:
				break;
		}
	}
	
}

SDL_Rect Paddle::getRect() {
	return { x, y, width, height };
}

void Paddle::update() {
	
	if (this->direction == Direction::UP) y -= speed;
	else if (this->direction == Direction::DOWN) y += speed;

}
 
#include "Ball.h"
#include <iostream>


Ball::Ball(int x, int y, int width, int height, int speed) : x(x), y(y), width(width), height(height), xVelocity(speed), yVelocity(speed) {

	if (rand() % 2 == 0) xVelocity = -xVelocity;
	if (rand() % 2 == 0) yVelocity = -yVelocity;
}

void Ball::render(SDL_Renderer* renderer) {

	SDL_Rect ballRect = getRect();
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderFillRect(renderer, &ballRect);
}

void Ball::update() {

	x += xVelocity;
	y += yVelocity;
}

SDL_Rect Ball::getRect() const {

	return { x, y, width, height };
}

std::pair<int, int> Ball::getVelocity() const {

	return std::make_pair(xVelocity, yVelocity);
}


void Ball::setVelocity(std::pair<int, int> velocity) {

	xVelocity = velocity.first;
	yVelocity = velocity.second;
}

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Coord.hpp"

class Entity {
public:
	Entity() {}
	Entity(float p_x, float p_y, float p_w, float p_h, SDL_Texture* p_tex, double p_r);

	void setX(double x) {position.x = x; }
	void setY(double y) {position.y = y; }
	void increaseX() { position.x++;}
	void decreaseX() { position.x--;}
	void increaseY() { position.y++;}
	void decreaseY() { position.y--;}
	Coord getPosition() const;

	void setRotation(double p_r) { rotation = p_r; }
	double getRotation() const { return rotation; }

	SDL_Texture* getTex() const;
	SDL_Rect getCurrentFrame() const;
private:
	Coord position;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
	double rotation;
};
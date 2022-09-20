#include "Entity.hpp"

Entity::Entity(float p_x, float p_y, float p_w, float p_h, SDL_Texture* p_tex, double p_r)
:tex(p_tex), rotation(p_r)
{
	position.x = p_x;
	position.y = p_y;

	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = p_w;
	currentFrame.h = p_h;
}

Coord Entity::getPosition() const {
	return position;
}

SDL_Texture* Entity::getTex() const {
	return tex;
}

SDL_Rect Entity::getCurrentFrame() const {
	return currentFrame;
}
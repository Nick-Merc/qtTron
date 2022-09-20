#pragma once
#include "Entity.hpp"
#include <string>

class Racer {
public:
	Racer() {}
	Racer(int p_x, int p_y, SDL_Texture* p_tex1, SDL_Texture* p_tex2);

	void setDirection(std::string direction) { this->direction = direction; }
	std::string getDirection() { return direction; }
	void setRotation(double p_r) { racerEntity.setRotation(p_r); }
	Coord getPosition() const { return position; }

	Entity getEntity() { return racerEntity; }
	Entity getTrail() { return racerTrailEntity; }

	void update();

private:
	std::string direction;
	Coord position;
	SDL_Texture* racerTexture;
	Entity racerEntity;
	SDL_Texture* racerTrailTexture;
	Entity racerTrailEntity;
};
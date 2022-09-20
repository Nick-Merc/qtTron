#include "Racer.hpp"

Racer::Racer(int p_x, int p_y, SDL_Texture* p_tex1, SDL_Texture* p_tex2)
	:direction("Up") {
	racerTexture = p_tex1;
	racerTrailTexture = p_tex2;

	position.x = p_x;
	position.y = p_y;
	
	racerEntity = Entity(p_x - 8, p_y - 21, 22, 47, p_tex1, 0);
	racerTrailEntity = Entity(p_x, p_y, 6, 6, p_tex2, 0);
}

void Racer::update() {
	if (direction == "Up") {
		position.y--;
		racerEntity.decreaseY();
		racerTrailEntity.decreaseY();
	}
	else if (direction == "Down") {
		position.y++;
		racerEntity.increaseY();
		racerTrailEntity.increaseY();
	}	
	else if (direction == "Left") {
		position.x--;
		racerEntity.decreaseX();
		racerTrailEntity.decreaseX();
	}
	else if (direction == "Right") {
		position.x++;
		racerEntity.increaseX();
		racerTrailEntity.increaseX();
	}
}
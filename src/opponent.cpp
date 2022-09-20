#include "Opponent.hpp"
#include <cmath>

Opponent::Opponent(double startX, double startY, SDL_Texture* p_r_tex, SDL_Texture* p_t_tex)
	:cooldown(false) {
	oRacer = Racer(startX, startY, p_r_tex, p_t_tex);
}

void Opponent::update(Racer p_racer) {
	targetPosition = getTargetPos(p_racer);

	int xDist, yDist;
	xDist = targetPosition.x - oRacer.getPosition().x;
	yDist = targetPosition.y - oRacer.getPosition().y;

	if (fabs(xDist) < fabs(yDist)) {
		if (yDist < 0) {
			oRacer.setDirection("Up");
		}
		else if (yDist >= 0) {
			oRacer.setDirection("Down");
		}
	}
	else if (fabs(xDist) > fabs(yDist)) {
		if (xDist < 0) {
			oRacer.setDirection("Left");
		}
		else if (xDist >= 0) {
			oRacer.setDirection("Right");
		}
	}

	oRacer.update();
}

Coord Opponent::getTargetPos(Racer p_racer) {
	Coord tmp = p_racer.getPosition();

	if (p_racer.getDirection() == "Up") {
		tmp.y-=10;
	}
	else if (p_racer.getDirection() == "Right") {
		tmp.x+=10;
	}
	else if (p_racer.getDirection() == "Down") {
		tmp.y+=10;
	}
	else if (p_racer.getDirection() == "Left") {
		tmp.x-=10;
	}

	return tmp;
}

void Opponent::turnRight() {
	std::string currD = oRacer.getDirection();

	if (currD == "Up") {
		oRacer.setDirection("Right");
	}
	else if (currD == "Right") {
		oRacer.setDirection("Down");
	}
	else if (currD == "Down") {
		oRacer.setDirection("Left");
	}
	else if (currD == "Left") {
		oRacer.setDirection("Up");
	}
}
void Opponent::turnLeft() {
	std::string currD = oRacer.getDirection();

	if (currD == "Up") {
		oRacer.setDirection("Left");
	}
	else if (currD == "Left") {
		oRacer.setDirection("Down");
	}
	else if (currD == "Down") {
		oRacer.setDirection("Right");
	}
	else if (currD == "Right") {
		oRacer.setDirection("Up");
	}
}
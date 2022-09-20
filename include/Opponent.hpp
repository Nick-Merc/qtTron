#include "Racer.hpp"

class Opponent {
public:
	Opponent() {}
	Opponent(double startX, double startY, SDL_Texture* p_r_tex, SDL_Texture* p_t_tex);
	void update(Racer p_racer);
	void turnRight();
	void turnLeft();
	Racer oRacer;
private:
	Coord getTargetPos(Racer p_racer);
	Coord targetPosition;
	char directions[4] = { 0, 1, 2, 3 };
	bool cooldown;
};
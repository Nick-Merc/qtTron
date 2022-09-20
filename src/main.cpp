#include "Tron.hpp"

int main(int argc, char* args[]) {
	int numI = 190; //Number of iterations to increase score.
	Tron tron; //Create game object.
	tron.gameRunning = true;
	tron.speed = 5; //Set game loop speed.

	SDL_Event event; //Used to poll for current event.

	int iteration = 0;
	while (tron.gameRunning) {
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					tron.gameRunning = false;
					break;

				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_UP) {
						tron.racer.setDirection("Up");
						tron.racer.setRotation(0);
					}
					else if (event.key.keysym.sym == SDLK_DOWN) {
						tron.racer.setDirection("Down");
						tron.racer.setRotation(180);
					}
					else if (event.key.keysym.sym == SDLK_LEFT) {
						tron.racer.setDirection("Left");
						tron.racer.setRotation(270);
					}
					else if (event.key.keysym.sym == SDLK_RIGHT) {
						tron.racer.setDirection("Right");
						tron.racer.setRotation(90);
					}

					else if (event.key.keysym.sym == SDLK_q) {
						tron.gameRunning = false;
					}
					break;

				default:
					break;
			}
		}

		tron.racer.update(); //Update coordinates for racer, racerEntity, and racerTrailEntity.

		if (iteration % 2 == 0) {
			tron.opponent.update(tron.racer);
		}

		if (tron.gameRunning) {
			tron.updateGame(); //Check to see if out of bounds.
		}

		tron.updatePositions(tron.racer, tron.racerTrailPositions, true, true); //Add trail position to list; if found, end game.
		tron.updatePositions(tron.opponent.oRacer, tron.opponentTrailPositions, false, true);

		tron.updatePositions(tron.racer, tron.opponentTrailPositions, true, false);

		if (iteration % numI == 0) {
			tron.increaseScore(); //Increase score every numI number of iterations.
		}

		//Render entities.
		tron.renderBackground();
		tron.renderScore();
		tron.renderTrail(tron.racer.getTrail(), tron.racerTrailPositions, 600, true);
		tron.renderTrail(tron.opponent.oRacer.getTrail(), tron.opponentTrailPositions, 250, false);
		tron.renderRacers();

		tron.window.display(); //Display rendered entities to screen.

		iteration++;
		
		SDL_Delay(tron.speed);
	}

	tron.window.clear();
	tron.window.cleanUp();
	SDL_Quit();

	std::cout << "Game Over!" << std::endl;
	std::cin.get();

	return 0;
}
#pragma once
#include "Racer.hpp"
#include "RenderWindow.hpp"
#include "Opponent.hpp"
#include <iostream>
#include <vector>

struct Tron {
public:
	Tron();
	void increaseScore();
	int * getScore() { return score; }
	void updateGame();
	void updatePositions(Racer p_racer, std::vector<std::vector<int>>& positions, bool canCrash, bool addPosition);

	void renderBackground();
	void renderScore();
	void renderRacers();
	void renderTrail(Entity trailEntity, std::vector<std::vector<int>> positions, int startY, bool mainRacer);

public:
	RenderWindow window;
	std::vector<SDL_Texture*> numberTextures;
	std::vector<SDL_Texture*> racerTextures;
	std::vector<SDL_Texture*> trailTextures;
	Entity background;
	Racer racer;
	Opponent opponent;
	int score[4] = {0, 0, 0, 0};
	int speed = 10;
	std::vector<std::vector<int>> racerTrailPositions;
	std::vector<std::vector<int>> opponentTrailPositions;
	bool gameRunning;
};
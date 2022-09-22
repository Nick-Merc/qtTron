..#include "Tron.hpp"

Tron::Tron() {
	RenderWindow newWindow("Tron Racer", 694, 745);
	window = newWindow;

	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	}
	if (!(IMG_Init(IMG_INIT_PNG))) {
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
	}

	char racerTexturePath[] = "..\\res\\gfx\\tronRacer.png";
	char trail1TexturePath[] = "..\\res\\gfx\\tronRacerTrail.png";
	char opponentTexturePath[] = "";
	char trail2TexturePath[] = "";
	racerTextures.push_back(window.loadTexture(racerTexturePath));
	trailTextures.push_back(window.loadTexture(trail1TexturePath));

	// SDL_Texture* opponentTexture = window.loadTexture(racerTexturePath);
	// SDL_Texture* trail2Texture = window.loadTexture(trail1TexturePath);

	racer = Racer(694/2, 694, racerTextures[0], trailTextures[0]);
	opponent = Opponent(694/2, 200, racerTextures[0], trailTextures[0]);

	char backgroundTexturePath[] = "..\\res\\gfx\\tronBackground.png";
	SDL_Texture* backgroundTexture = window.loadTexture(backgroundTexturePath);
	Entity backgroundE(0, 0, 694, 745, backgroundTexture, 0);
	background = Entity(0, 0, 694, 745, backgroundTexture, 0);

	for (int i = 0; i < 700; ++i)
	{
		racerTrailPositions.push_back(std::vector<int>());
	}
	for (int i = 0; i < 700; ++i)
	{
		opponentTrailPositions.push_back(std::vector<int>());
	}

	numberTextures.push_back(window.loadTexture("..\\res\\gfx\\tronLetters\\tron0.png"));
	numberTextures.push_back(window.loadTexture("..\\res\\gfx\\tronLetters\\tron1.png"));
	numberTextures.push_back(window.loadTexture("..\\res\\gfx\\tronLetters\\tron2.png"));
	numberTextures.push_back(window.loadTexture("..\\res\\gfx\\tronLetters\\tron3.png"));
	numberTextures.push_back(window.loadTexture("..\\res\\gfx\\tronLetters\\tron4.png"));
	numberTextures.push_back(window.loadTexture("..\\res\\gfx\\tronLetters\\tron5.png"));
	numberTextures.push_back(window.loadTexture("..\\res\\gfx\\tronLetters\\tron6.png"));
	numberTextures.push_back(window.loadTexture("..\\res\\gfx\\tronLetters\\tron7.png"));
	numberTextures.push_back(window.loadTexture("..\\res\\gfx\\tronLetters\\tron8.png"));
	numberTextures.push_back(window.loadTexture("..\\res\\gfx\\tronLetters\\tron9.png"));
	numberTextures.push_back(window.loadTexture("..\\res\\gfx\\tronLetters\\tronBlank.png"));
}

void Tron::renderScore() {
	int startX = 255;
	int startY = 702;
	for (int i = 0; i < 4; ++i)
	{
		Entity blank(startX + (i * 15), startY, 9, 15, numberTextures[10], 0);
		window.render(blank);

		Entity number(startX + (i * 15), startY, 15, 15, numberTextures[score[i]], 0);
		window.render(number);
	}
}

void Tron::increaseScore() {
	score[3]++;
	for (int i = 3; i >= 0; --i)
	{
		if (score[i] == 10 && i != 0) {
			score[i] = 0;
			score[i-1]++;
		}
	}
}

void Tron::updateGame() {
	Coord pos = racer.getPosition();
	if (pos.x < 45 || pos.x >= 645 || pos.y < 140 || pos.y >= 695) {
		gameRunning = false;
	}
}

void Tron::renderBackground() {
	window.clear();
	window.render(background);
}

void Tron::renderRacers() {
	Entity tmp = racer.getEntity();
	window.render(tmp);
	tmp = opponent.oRacer.getEntity();
	window.render(tmp);
}

void Tron::renderTrail(Entity trailEntity, std::vector<std::vector<int>> positions, int startY, bool mainRacer) {
	if (mainRacer) {
		for (int i = 0; i < 4; ++i) //Bottom of trail.
		{
			trailEntity.setX(694/2);
			trailEntity.setY(695 + (i * 6));
			window.render(trailEntity);
		}
	}
	trailEntity.setX(694/2);
	trailEntity.setY(startY);
	window.render(trailEntity);

	for (unsigned int i = 0; i < positions.size(); ++i) {
		for (unsigned int q = 0; q < positions[i].size(); ++q) {
			trailEntity.setX(i);
			trailEntity.setY(positions[i][q]);
			window.render(trailEntity);
		}
	}
}

void Tron::updatePositions(Racer p_racer, std::vector<std::vector<int>>& positions, bool canCrash, bool addPosition) {
	bool foundY = false;
	Coord pos = p_racer.getPosition();

	for (unsigned int i = 0; i < positions[pos.x].size() && !foundY; ++i) {
		if (positions[pos.x][i] == pos.y) {
			foundY = true;
			if (canCrash) {
				gameRunning = false;
			}
		}
	}

	if (addPosition) {
		if (!foundY) {
			positions[pos.x].push_back(pos.y);
		}
	}
}

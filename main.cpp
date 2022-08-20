#include <stdio.h>
#include <SDL2/SDL.h>
#include "Game.h"

Game* game = 0;

int main(int argc, char **argv)
{
	game = new Game();
	game->init("Chapter 1: Setting up SDL", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
		480, 640, SDL_WINDOW_SHOWN);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	// clean up SDL
	game->clean();

	return 0;
}
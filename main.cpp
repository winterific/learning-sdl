#include <stdio.h>
#include <SDL2/SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char** argv) {

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		g_pWindow = SDL_CreateWindow("Chapter 1: Setting up SDL", 
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480,
			SDL_WINDOW_SHOWN);

		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else {
		return 1; // SDL could not initialize
	}

	// everything succeeded! let's draw the window

	// set to black // this function expects read, green, blue and alpha as color values
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

	// clear window to black
	SDL_RenderClear(g_pRenderer);

	// show the window
	SDL_RenderPresent(g_pRenderer);

	// set a delay before quitting
	SDL_Delay(5000);

	// clean up SDL
	SDL_Quit();

	return 0;
}
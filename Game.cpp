#include "Game.h"

void Game::init(const char *title, int xpos, int ypos, int height, int width, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1,
										  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			m_bRunning = true;
		}
		else {
			m_bRunning = false;
		}
	}
	else
	{
		m_bRunning = false;
	}
}

void Game::render()
{
	// set to black // this function expects read, green, blue and alpha as color values
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);

	// clear window to black
	SDL_RenderClear(m_pRenderer);

	// show the window
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {

}

void Game::clean() {
	std::cout << "Cleaning up game" << std::endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
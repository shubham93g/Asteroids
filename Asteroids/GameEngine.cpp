#include "GameEngine.h"


GameEngine::GameEngine()
{	// init SDL
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Asteroids",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
}


GameEngine::~GameEngine()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void GameEngine::init()
{
	SDL_Delay(0.1);
}

bool GameEngine::handleInputAndUpdate(GameState &gameState)
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type){
		case SDL_QUIT:return true;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			const Uint8 *keyState = SDL_GetKeyboardState(NULL);
			gameState.handleInput(keyState);
			break;
	}
	
	gameState.update();
	return false;
}

void GameEngine::draw(GameState &gameState)
{

		// clear window

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// TODO rendering code goes here

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

		//SDL_RenderDrawLine(renderer, 5, 5, 5, 100);

		std::vector<std::vector<SDL_Point>> points = gameState.getVectorPoints();
		for (std::vector<SDL_Point> point : points) {
			SDL_RenderDrawLines(renderer, point.data(), point.capacity());
		}


		// render window

		SDL_RenderPresent(renderer);
}

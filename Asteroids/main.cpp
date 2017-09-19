#include <iostream>
#include "GameEngine.h"

int main(int argc, char **argv) {
	GameEngine engine;
	GameState state;
	int quit = false;
	do {
		engine.init();
		quit = engine.handleInputAndUpdate(state);
		engine.draw(state);
	} while (!quit);
	return 0;
}
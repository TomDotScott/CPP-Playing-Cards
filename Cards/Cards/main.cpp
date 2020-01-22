#pragma once
#include <iostream>
#include "deck.hpp"
#include "time.h"
#include "hand.h"
#include "game.h"

int main()
{
	srand(time(NULL));

	//initialise the game
	Game game;
	game.Play();
}

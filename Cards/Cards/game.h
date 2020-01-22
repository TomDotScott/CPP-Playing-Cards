#pragma once
#include "deck.hpp"
#include "playing_card.hpp"
#include "hand.h"

class Game
{
private:
	//store all of the players in the game and whether they are still in or not
	//USER IS PLAYER 1 (INDEX 0)
	std::vector<std::pair<Hand, bool>> players;
	
	//the deck of cards
	Deck deck;
public:
	Game();
};


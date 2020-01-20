#pragma once
#include <iostream>
#include "deck.hpp"
#include "time.h"

int main()
{
	srand(time(NULL));

	//create the deck
	Deck theDeck;
	//output standard deck
	std::cout << theDeck << std::endl;
	//shuffle the deck
	theDeck.Shuffle();
	//output shuffled deck

	std::cout << theDeck << std::endl;
}

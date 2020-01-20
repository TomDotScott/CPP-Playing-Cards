#pragma once
#include <iostream>
#include "deck.hpp"
#include "time.h"

int main()
{
	srand(time(NULL));

	//create the deck
	Deck deck;
	//output standard deck
	std::cout << deck << std::endl;
	//shuffle the deck
	deck.Shuffle();
	//output shuffled deck

	std::cout << deck << std::endl;
}

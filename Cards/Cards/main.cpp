#pragma once
#include <iostream>
#include "deck.hpp"
#include "time.h"
#include "hand.h"

int main()
{
	srand(time(NULL));

	//create the deck
	Deck deck;

	//create the hand
	Hand hand;

	//shuffle the deck
	deck.Shuffle();

	for (int i = 0; i < 5; ++i) {
		PlayingCard card = deck.Deal();
		std::cout << card << std::endl;
		hand.Add(card);
	}

	std::cout << hand.Value() << std::endl;
}

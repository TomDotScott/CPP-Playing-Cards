#pragma once
#include "playing_card.hpp"
class Hand {
private:
	PlayingCard cards[5];
	int cards_in_hand = 0;
public:
	Hand() = default;
	void Add(PlayingCard& playingCard);
	int Value();
	void Display();
};

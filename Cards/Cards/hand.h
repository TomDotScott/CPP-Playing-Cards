#pragma once
#include "playing_card.hpp"
class Hand {
private:
	PlayingCard cards[5];
	int cards_in_hand = 0;
public:
	void add(PlayingCard& playingCard);
	int value();
	void display();
};
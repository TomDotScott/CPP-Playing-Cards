#pragma once
#include "playing_card.hpp"
#include <vector>
class Hand {
private:
	std::vector<PlayingCard> cards;
	//PlayingCard cards[5];
	int cards_in_hand = 0;
public:
	Hand() = default;
	void Add(PlayingCard& playingCard);
	void Add(PlayingCard& playingCard, int limit);
	int Value();
	void Display();
};

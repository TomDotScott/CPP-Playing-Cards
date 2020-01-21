#pragma once
#include "playing_card.hpp"
#include <vector>
#include <utility>
#include <iostream>

class Deck {
private:
	int total_playing_cards;
	int next_card_to_deal = 0;
	PlayingCard deck[52];

public:
	void Build();
	void Shuffle();
	PlayingCard Deal();
	friend std::ostream& operator <<(std::ostream& os, const Deck& deck);
	Deck();
	~Deck() {};
};

inline std::ostream& operator<<(std::ostream& os, const Deck& deck) {
	
	for (const std::pair<int, int>& i : deck.deck)
	{
		return std::cout << i.first << " " << i.second << std::endl;
	}
}
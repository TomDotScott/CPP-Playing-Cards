#pragma once
#include "deck.hpp"
#include <iostream>

Deck::Deck() {
	Build();
}

//builds the deck of cards by assigning the suits and the faces
void Deck::Build() {
	std::pair<int, int> faceSuit;
	//the face
	for (size_t i = 2; i < 15; i++)
	{
		faceSuit.first = i;
		//the suit
		for (size_t j = 1; j < 5; j++)
		{
			faceSuit.second = j;
			theDeck.push_back(faceSuit);
		}
	}
}

//shuffles the cards using the Fisher-Yates Shuffle algorithm 
//https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
void Deck::Shuffle() {
	for (int i = theDeck.size() - 1; i > 1; i--) {
		int random = rand() % theDeck.size() + 1;
		std::pair<int, int> temp = theDeck[i];
		theDeck[i] = theDeck[random];
		theDeck[random] = temp;
	}
}

//deals the next card form the deck
PlayingCard Deck::Deal() {
	if (next_card_to_deal > theDeck.size() - 1) {
		std::cout << "DECK HAS BEEN FULLY DEALT";
		return PlayingCard(0, 0);
	}
	else {
		std::pair<int, int> card = theDeck[next_card_to_deal];
		next_card_to_deal += 1;
		return PlayingCard(card.first, card.second);
	}
}
#pragma once
#include "deck.hpp"
#include <iostream>

Deck::Deck() {
	Build();
	total_playing_cards = 52;
}

//builds the deck of cards by assigning the suits and the faces
void Deck::Build() {
	int current = 0;
	//the face
	for (int face = 1; face < 13; ++face)
	{
		//the suit
		for (int suit = 1; suit < 5; ++suit)
		{
			deck[current] = PlayingCard(face, suit);
			current++;
		}
	}
}

//shuffles the cards using the Fisher-Yates Shuffle algorithm 
//https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
void Deck::Shuffle() {
	for (int i = 51; i > 1; i--) {
		int random = rand() % 51 + 1;
		PlayingCard temp = deck[i];
		deck[i] = deck[random];
		deck[random] = temp;
	}
}

//deals the next card form the deck
PlayingCard Deck::Deal() {
	if (next_card_to_deal > 52 - 1) {
		std::cout << "DECK HAS BEEN FULLY DEALT";
		return PlayingCard(0, 0);
	}
	else {
		PlayingCard card = deck[next_card_to_deal];
		next_card_to_deal += 1;
		return card;
	}
}

//Display the deck to the console
void Deck::Display(){
	for (PlayingCard &playingCard : deck) {
		std::cout << playingCard << std::endl;
	}
}
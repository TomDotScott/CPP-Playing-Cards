#include "hand.h"

void Hand::Add(PlayingCard& playingCard) {
	cards.push_back(playingCard);
	++cards_in_hand;
}

void Hand::Add(PlayingCard& playingCard, int limit) {
	//check if hand is full
	if (cards_in_hand != limit) {
		cards[cards_in_hand] = playingCard;
		++cards_in_hand;
	}
}

int Hand::Value() {
	int total{ 0 };
	for (PlayingCard& playingCard : cards) {
		total += playingCard.GetFaceValue();
	}
	return total;
}

void Hand::Display() {
	std::cout << "YOU HAVE: " << std::endl;
	for (PlayingCard& playingCard : cards) {
		std::cout << playingCard << std::endl;
	}
}

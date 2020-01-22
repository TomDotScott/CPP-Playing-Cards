#include "hand.h"

void Hand::Add(PlayingCard& playingCard) {
	//check if hand is full
	if (cards_in_hand != 5) {
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
	for (PlayingCard& playingCard : cards) {
		std::cout << playingCard << std::endl;
	}
}

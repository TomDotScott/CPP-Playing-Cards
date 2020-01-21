#include "hand.h"

void Hand::Add(PlayingCard& playingCard) {
	//check if hand is full
	if (cards_in_hand != 5) {
		cards[cards_in_hand] = playingCard;
		++cards_in_hand;
	}
}

int Hand::Value() {
	return 1;
}

void Hand::Display() {

}

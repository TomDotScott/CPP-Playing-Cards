#pragma once
#include <iostream>

class PlayingCard {
private:
	int face_value;
	int suit;
public:

	friend std::ostream& operator <<(std::ostream& os, const PlayingCard& playingCard);


	const int GetFaceValue() {
		return face_value;
	}
	const int GetSuit() {
		return suit;
	}
	PlayingCard() = default;
	PlayingCard(int face, int suit);
};

inline std::ostream& operator<<(std::ostream& os, const PlayingCard& playingCard) {
	return std::cout << playingCard.face_value << " " << playingCard.suit << std::endl;
}
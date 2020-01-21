#pragma once
#include <iostream>
#include <string>

class PlayingCard {
private:
	int face;
	int suit;
public:

	friend std::ostream& operator <<(std::ostream& os, const PlayingCard& playingCard);


	const int GetFaceValue() {
		return face;
	}

	const int GetSuit() {
		return suit;
	}
	PlayingCard() = default;
	PlayingCard(int face, int suit);
};

inline std::ostream& operator<<(std::ostream& os, const PlayingCard& playingCard) {
	std::string face_value = std::to_string(playingCard.face);
	//FIND THE FACE (WHETHER ACE, JACK, QUEEN OR KING)
	if (playingCard.face == 1) {
		face_value = "ACE";
	} else if (playingCard.face > 9) {
		if (playingCard.face == 10) {
			face_value = "JACK";
		}
		else if (playingCard.face == 11) {
			face_value = "QUEEN";
		}
		else {
			face_value = "KING";
		}
	} 


	switch (playingCard.suit)
	{
	case 1:
		return std::cout << face_value << " OF SPADES"<< std::endl;
		break;
	case 2:
		return std::cout << face_value << " OF CLUBS" << std::endl;
		break;
	case 3:
		return std::cout << face_value << " OF DIAMONDS" << std::endl;
		break;
	case 4:
		return std::cout << face_value << " OF HEARTS" << std::endl;
		break;
	default:
		break;
	}
}
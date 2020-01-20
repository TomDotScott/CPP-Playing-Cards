#pragma once

//------------------
//TODO: In Practical
//------------------


class PlayingCard {
private:
	int face_value;
	int suit;
public:
	const int GetFaceValue() {
		return face_value;
	}
	const int GetSuit() {
		return suit;
	}
	PlayingCard(int face, int suit);
};
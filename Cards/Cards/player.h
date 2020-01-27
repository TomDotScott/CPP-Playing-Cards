#pragma once
#include "hand.h"

class Deck;

class Player
{
private:
	bool liveStatus = true;
public:
	Hand hand;

	void TakeTurn(Deck& deck);

	int HitOrPass();


	bool GetLiveStatus() {
		return liveStatus;
	}
	void setLiveStatus(bool valueToSet) {
		liveStatus = valueToSet;
	}
};


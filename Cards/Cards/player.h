#pragma once
#include "hand.h"

class Player
{
private:
	bool liveStatus = true;
public:
	Hand hand;

	bool GetLiveStatus() {
		return liveStatus;
	}
	void setLiveStatus(bool valueToSet) {
		liveStatus = valueToSet;
	}
};


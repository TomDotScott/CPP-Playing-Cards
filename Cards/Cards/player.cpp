#pragma once
#include "player.h"
#include "deck.hpp"

void Player::TakeTurn(Deck& deck) {
	std::cout << "PLAYER 1" << std::endl;
	bool stillTurn = true;
	do {
		int hitOrPass = HitOrPass();
		switch (hitOrPass)
		{
			//if a hit
		case 1:
			//deal a card to the player
			PlayingCard nextCard = deck.Deal();
			hand.Add(nextCard);
			//display the Player's cards
			hand.Display();
			std::cout << "WITH A VALUE OF " << hand.Value() << std::endl;

			break;
		case 2:
			stillTurn = false;
			break;
		default:
			break;
		}
	} while (stillTurn);
}

int Player::HitOrPass() {
	bool validInput = true;
	int hitOrPass;
	do {
		std::cout << "Would you like to HIT (1) or PASS (2)?" << std::endl;
		std::cin >> hitOrPass;
		//input validation
		if (!std::cin.good() || hitOrPass > 2 || hitOrPass < 1) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "A valid input is 1 or 2" << std::endl;
			validInput = false;
		}
		else {
			validInput = true;
		}
	} while (!validInput);
	return hitOrPass;
}

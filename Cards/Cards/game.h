#pragma once
#include "deck.hpp"
#include "playing_card.hpp"
#include "hand.h"

class Game
{
private:
	//store all of the players in the game and whether they are still in or not
	//USER IS PLAYER 1 (INDEX 0)
	std::vector<std::pair<Hand, bool>> players;
	
	//the deck of cards
	Deck deck;

	//whether the game has been won or not
	bool gameWon = false;

	//Whose turn it is to play
	int turn{ 0 };

	//the amount of players who are still 'alive'
	int alivePlayers{ 0 };

	//print the value of everyoen who is still in the game's cards
	void DisplayCards();

	//increment whose turn it is
	void IncrementPlayer();

public:
	Game();
	void Play();
};


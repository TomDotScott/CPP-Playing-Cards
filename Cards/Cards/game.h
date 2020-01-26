#pragma once
#include "deck.hpp"
#include "playing_card.hpp"
#include "hand.h"
#include "player.h"

class Game
{
private:
	//store all of the players in the game and whether they are still in or not
	Player player;

	//each of the bots in the game
	std::vector<std::pair<Hand, bool>> computers;
	
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

	//print the value of a specific player's cards
	void DisplayCards(int playerNumber);

	//A method to deal with it being the Player's Turn
	void PlayersTurn();

	//returns 1 for hit or 2 for pass
	int PlayerHitOrPass();

	//A method to deal wiht it being the computers' turn
	void ComputersTurn();

	//returns 1 for hit or 2 for pass
	int ComputerHitOrPass();

	//increment whose turn it is
	void IncrementPlayer();

	//Populate the computers vector
	void GenerateComputers();

public:
	Game();
	void Play();
};


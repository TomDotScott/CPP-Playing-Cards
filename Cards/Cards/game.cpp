#include "game.h"
/*------------------------TODO---------------------------------------------

  -ACE can be 1 or 11                                                           
  -JACK, QUEEN and KING are 10 points                                           
  -the CARDS are SHUFFLED                                                       
  -each player is DEALT 2 CARDS                                                  
  -the player is told the VALUE of their HAND                                     
  -players decide whether to HIT or PASS                                              
  -if HIT, the player has another CARD in their HAND                                  
  -their total is told to them      
  -players can be hit ONCE per round 
  -if their new total is MORE THAN 21, they LOSE and are out of the game
  -once the players have all chosen to HIT or PASS, the DECK is SHUFFLED again       
  -when everyone has decided to PASS, their totals are worked out
  -the player with the total closest to 21 wins

-------------------------------------------------------------------------*/

//initialise the game by creating the computer vector and handing out cards to the players
Game::Game() {
	deck.Shuffle();

	//add to the player's hand
	for (int i = 0; i < 2; i++)
	{
		PlayingCard nextCard = deck.Deal();
		player.hand.Add(nextCard);
	}

	GenerateComputers();

	//account for the user as well
	alivePlayers = computers.size() + 1;
}

void Game::GenerateComputers()
{
	//create the hands of the computers
	for (int i = 0; i < 5; i++)
	{
		Hand computerHand;
		for (int j = 0; j < 2; j++)
		{
			PlayingCard nextCard = deck.Deal();
			computerHand.Add(nextCard);
		}
		std::pair<Hand, bool> computer;
		computer.first = computerHand;
		computer.second = true;
		computers.push_back(computer);
	}
}

void Game::Play() {
	while (gameWon != true) {
		//Tell the players the value of their hands
		DisplayCards();
		//Ask the plyers whether they would like to HIT or PASS
		if (turn == 0) {
			//if player 1 is still playing
			if (player.GetLiveStatus() == true) {
				PlayersTurn();
			}
		}
		else {
			ComputersTurn();
		}
	}
}

void Game::DisplayCards() {
	player.hand.Display();
	std::cout << "WITH A VALUE OF " << player.hand.Value() << std::endl;

	for (int i = 0; i < computers.size(); ++i) {
		std::cout << "CPU " << i + 1 << ", ";
		int playerTotal{ 0 };
		//only output if the computer is still in the game
		if (computers[i].second == true) {
			//Display the cards in each computers' hands
			computers[i].first.Display();
		}
		std::cout << "WITH A VALUE OF " << computers[i].first.Value() << std::endl << std::endl;
	}
}

void Game::DisplayCards(int playerNumber) {
	computers[playerNumber].first.Display();
	std::cout << "WITH A VALUE OF " << computers[playerNumber].first.Value() << std::endl << std::endl;
}

void Game::IncrementPlayer() {
	//if it is the last players' turn
	if (turn == computers.size() + 1) {
		turn = 0;
	}
	else {
		turn++;
	}
}

void Game::PlayersTurn() {
	std::cout << "PLAYER 1" << std::endl;
	bool stillTurn = true;
	do {
		int hitOrPass = PlayerHitOrPass();
		switch (hitOrPass)
		{
			//if a hit
		case 1:
			//deal a card to the player
			PlayingCard nextCard = deck.Deal();
			player.hand.Add(nextCard);
			//display the Player's cards
			player.hand.Display();
			std::cout << "WITH A VALUE OF " << player.hand.Value() << std::endl;

			break;
		case 2:
			stillTurn = false;
			break;
		default:
			break;
		}
	} while (stillTurn);
	//next player's turn
	IncrementPlayer();
}

int Game::PlayerHitOrPass() {
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

void Game::ComputersTurn() {
	//go through all of the CPUs 
	for (std::pair<Hand, bool>& CPU : computers)
	{
		//if they are still alive
		if (CPU.second == true) {
			//------------TODO----------------
			//MAKE THE CPUs IMPLEMENT SOME 
			//SORT OF STRATEGY. FOR NOW, I AM 
			//GOING TO KEEP IT RANDOM
			//--------------------------------


			//decide to hit or pass
			bool stillTurn = true;
			do {
				int hitOrPass = rand() % 2 + 1;
				switch (hitOrPass)
				{
				case 1:
					PlayingCard nextCard = deck.Deal();
					CPU.first.Add(nextCard);
					break;
				case 2:
					stillTurn = false;
				default:
					break;
				}
			} while (stillTurn);
		}
		IncrementPlayer();
	}
}


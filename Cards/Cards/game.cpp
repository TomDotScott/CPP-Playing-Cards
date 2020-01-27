#include "game.h"
/*------------------------TODO---------------------------------------------

  -ACE can be 1 or 11                                                           
  -JACK, QUEEN and KING are 10 points DONE                                           
  -the CARDS are SHUFFLED                  DONE                                      
  -each player is DEALT 2 CARDS                DONE                                  
  -the player is told the VALUE of their HAND      DONE                               
  -players decide whether to HIT or PASS               DONE                               
  -if HIT, the player has another CARD in their HAND       DONE                           
  -their total is told to them      DONE
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
				player.TakeTurn(deck);
			}
		}
		else {
			ComputersTurn();
		}
		IncrementPlayer();
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
				/*
				int hitOrPass{ 0 };

				//strategy from https://www.pagat.com/images/banking/bjbasic.jpg
				switch (CPU.first.Value)
				{
				case 5:
					hitOrPass = 1;
					break;
				case 6:
					hitOrPass = 1;
					break;
				case 7:
					hitOrPass = 1;
					break;
				case 8:
					hitOrPass = 1;
					break;
				case 9:
					if (CPU.first.GetDealerUpCard().GetFaceValue() == 2) {
						hitOrPass = 1;
					}
					else if (CPU.first.GetDealerUpCard().GetFaceValue() == 3 || CPU.first.GetDealerUpCard().GetFaceValue() == 4 || CPU.first.GetDealerUpCard().GetFaceValue() == 5 || 
						CPU.first.GetDealerUpCard().GetFaceValue() == 6) {
						hitOrPass = rand() % 2 + 1;
					}
					else {
						hitOrPass = 1;
					}
					break;
				case 10:
					if (CPU.first.GetDealerUpCard().GetFaceValue() <= 9) {
						hitOrPass = rand() % 2 + 1;
					}
					else {
						hitOrPass = 1;
					}
					break;
				case 11:
					if (CPU.first.GetDealerUpCard().GetFaceValue() <= 10) {
						hitOrPass = rand() % 2 + 1;
					}
					else {
						hitOrPass = 1;
					}
					break;
				case 12:
					if (CPU.first.GetDealerUpCard().GetFaceValue() == 2 || CPU.first.GetDealerUpCard().GetFaceValue() == 3) {
						hitOrPass = 1;
					}
					else if (CPU.first.GetDealerUpCard().GetFaceValue() == 4 || CPU.first.GetDealerUpCard().GetFaceValue() == 5 || CPU.first.GetDealerUpCard().GetFaceValue() == 6) {
						hitOrPass = 0;
					}
					else {
						hitOrPass = rand() % 2 + 1;
					}
					break;
				case 13:
					if (CPU.first.GetDealerUpCard().GetFaceValue() <= 6) {
						hitOrPass = 0;
					}
					else {
						hitOrPass = rand() % 2 + 1;
					}
					break;

				case 14:
					if (CPU.first.GetDealerUpCard().GetFaceValue() <= 6) {
						hitOrPass = 0;
					}
					else {
						hitOrPass = rand() % 2 + 1;
					}
					break;
				case 15:
					if (CPU.first.GetDealerUpCard().GetFaceValue() <= 6) {
						hitOrPass = 0;
					}
					else {
						hitOrPass = rand() % 2 + 1;
					}
					break;
				case 16:
					if (CPU.first.GetDealerUpCard().GetFaceValue() <= 6) {
						hitOrPass = 0;
					}
					else {
						hitOrPass = rand() % 2 + 1;
					}
					break;
				default:
					break;
				}
				*/

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


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

//initialise the game by creating the player vector
Game::Game() {
	deck.Shuffle();
	//create the hands of the players
	for (int i = 0; i < 2; i++)
	{
		Hand playerHand;
		for(int j = 0; j < 2; j++)
		{
			PlayingCard nextCard = deck.Deal();
			playerHand.Add(nextCard);
		}
		std::pair<Hand, bool> player;
		player.first = playerHand;
		player.second = true;
		players.push_back(player);
	}

	alivePlayers = players.size();
}

void Game::Play() {
	while (gameWon != true) {
		//Tell the players the value of their hands
		DisplayCards();
		//Ask the plyers whether they would like to HIT or PASS
		//if player 1 is still playing
		if (players[0].second == true) {
			PlayersTurn();
		}


		//next player's turn
		IncrementPlayer();
	}
}

void Game::DisplayCards() {
	for (int i = 0; i < players.size(); ++i) {
		std::cout << "PLAYER " << i + 1 << " ";
		int playerTotal{ 0 };
		//only output if the player is still in the game
		if (players[i].second == true) {
			//Display the cards in each player's hands
			players[i].first.Display();
		}
		std::cout << "WITH A VALUE OF " << players[i].first.Value() << std::endl;
	}
}

void Game::IncrementPlayer() {
	//if it is the last players' turn
	if (turn == players.size()) {
		turn = 0;
	}
	else {
		++turn;
	}
}

void Game::PlayersTurn() {
	bool validInput = true;
	do {
		int hitOrPass;
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
}
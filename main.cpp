#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include "Suite.h"
#include "Player.h"
#include "Card.h"
#include <time.h>


int main()
{
	srand(time(NULL));
	std::deque<Card*> deck;
	Player player = Player();
	Player house = Player();
	int turn = 0;
	char choice = 'y';
	for (int i = 2; i <= 14; i++)
	{
		if (i == 14)
		{
	        deck.push_back(new Card("As", 11, Suite::Hearts));
	        deck.push_back(new Card("As", 11, Suite::Spades));
			deck.push_back(new Card("As", 11, Suite::Diamonds));
			deck.push_back(new Card("As", 11, Suite::Clubs));
		}
		if (i == 13)
		{
			deck.push_back(new Card("Kralj", 10, Suite::Hearts));
			deck.push_back(new Card("Kralj", 10, Suite::Spades));
			deck.push_back(new Card("Kralj", 10, Suite::Diamonds));
			deck.push_back(new Card("Kralj", 10, Suite::Clubs));
		}
		if (i == 12)
		{
			deck.push_back(new Card("Cura", 10, Suite::Hearts));
			deck.push_back(new Card("Cura", 10, Suite::Spades));
			deck.push_back(new Card("Cura", 10, Suite::Diamonds));
			deck.push_back(new Card("Cura", 10, Suite::Clubs));
		}
		if (i == 11)
		{
			deck.push_back(new Card("Decko", 10, Suite::Hearts));
			deck.push_back(new Card("Decko", 10, Suite::Spades));
			deck.push_back(new Card("Decko", 10, Suite::Diamonds));
			deck.push_back(new Card("Decko", 10, Suite::Clubs));
		}
		if (i <= 10)
		{
			deck.push_back(new Card("Broj", i, Suite::Hearts));
			deck.push_back(new Card("Broj", i, Suite::Spades));
			deck.push_back(new Card("Broj", i, Suite::Diamonds));
			deck.push_back(new Card("Broj", i, Suite::Clubs));
		}
	}
	std::random_shuffle(deck.begin(), deck.end());
	
		while (choice == 'y')
		{
			player.addObj(*deck[deck.size() - 1]);
			deck.pop_back();
			if (player.getHandValue(turn) == 11 && turn > 0 && player.previousValue() >= 11)
			{
				player.changeValue(1, turn);
			}
			++turn;
			if (house.pValue() < 17 && turn == 1)
			{
				house.addObj(*deck[deck.size() - 1]);
				deck.pop_back();
			}
			if (house.pValue() < 17 && turn >= 3)
			{
				house.addObj(*deck[deck.size() - 1]);
				deck.pop_back();
			}
			if (turn >= 2)
			{
				player.showHand();
				std::cout << "Player value:" << player.pValue() << std::endl;
				std::cout << "###########################" << std::endl;
				house.showHand();
				std::cout << "House value:" << house.pValue() << std::endl;

			}
			if (player.pValue() > 21)
			{
				choice = 'y';
				break;
			}
			if (house.pValue() > 21)
			{
				choice = 'y';
				break;
			}
			if (turn >= 2)
			{
				std::cout << "More? (y/n)" << std::endl;
				std::cin >> choice;
				
			}
			
		}
		while (house.pValue() < 17)
		{
			std::cout << "HHHHHHHHHHHHHHHHHHH" << std::endl;
			if (house.pValue() < 17)
			{
				house.addObj(*deck[deck.size() - 1]);
				deck.pop_back();
			}
			house.showHand();
			
			std::cout << "House value: " << house.pValue() << std::endl;
			std::cout << "HHHHHHHHHHHHHHHHHHH" << std::endl;
		}
		if (house.pValue() > 21 && player.pValue() <= 21)
		{
			std::cout << "You won!" << std::endl;
		}
		else if (player.pValue() > 21)
		{
			std::cout << "You lost!" << std::endl;
		}

		else if (player.pValue() == house.pValue())
		{
			std::cout << "It's a tie!" << std::endl;
		}

		else if (player.pValue() > house.pValue() && player.pValue() <= 21)
		{
			std::cout << "You won!" << std::endl;
		}
		else
		{
			std::cout << "You lost!" << std::endl;
		}
		system("pause");
}

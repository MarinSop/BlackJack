#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include "Suite.h"



class Card
{
public:
	Card(std::string name, int value, Suite suite)
	{
		_name = name;
		_value = value;
		_suite = suite;
	}
	~Card();

	friend std::ostream &operator<<(std::ostream &os, const Card &value)
	{
		os << value._name << "," << value._value << "," << value._suite;
		return os;
	}


private:
	std::string _name;
	int _value;
	Suite _suite;
};

class Player
{
public:
	Player(std::string name, Card hand)
	{
		_name = name;
		_hand.push_back(hand);
		
	}
	~Player();

private:
	std::string _name;
	std::vector<Card> _hand;

};

int main()
{
	
	std::deque<Card*> deck;
	std::vector<Player> players;
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
	
	Player player("dad",Card("Broj", 5, Suite::Clubs));

	
	/*for (Card* c : deck)
	{
		std::cout << *c << std::endl;
	}*/
	system("pause");
}
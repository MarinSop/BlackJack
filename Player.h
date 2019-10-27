#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Suite.h"
class Player
{
public:
	Player();
	~Player();
	void addObj(Card obj);
	void showHand();
	int pValue();
	int getHandValue(int value);
	std::string getCardName(int value);
	void changeValue(int value, int i);
	int getHandCardNumber();
	int previousValue();
private:
	std::string _name;
	std::vector<Card> _hand;
};


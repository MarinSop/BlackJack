#include "Player.h"
#include <iostream>

Player::Player()
{
}


Player::~Player()
{
}

void Player::addObj(Card obj)
{
	_hand.push_back(obj);
}

void Player::showHand()
{
	for (auto it : _hand)
	{
		it.displayCard();
	}
}

int Player::pValue()
{
	
	int result = 0;
	for (auto it : _hand)
	{
		result += it.getValue();
	}
	return result;
}

int Player::getHandValue(int value)
{
	return _hand[value].getValue();

}

std::string Player::getCardName(int value)
{
	return _hand[value].getName();
}

void Player::changeValue(int value, int i)
{
	_hand[i].changeCardValue(value);
}

int Player::getHandCardNumber()
{
	return _hand.size()-1;
}

int Player::previousValue()
{
	int result= 0;
	for (int i = 0; i < _hand.size()-1; i++)
	{
		result += _hand[i].getValue();
	}
	return result;

}

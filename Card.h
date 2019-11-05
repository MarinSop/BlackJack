#pragma once
#include <string>
#include <vector>
#include "Suite.h"
#include <iostream>

class Card
{
public:
	Card(std::string name, int value, Suite suite);

	~Card();


	void displayCard();
	int getValue();
	std::string getName();
	void changeCardValue(int value);

private:
	std::string _name;
	int _value;
	Suite _suite;
};


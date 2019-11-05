#include "Card.h"

Card::Card(std::string name, int value, Suite suite)
{
	_name = name;
	_value = value;
	_suite = suite;
}


Card::~Card()
{


}


void Card::displayCard()
{
	std::cout << _name << " " << _value << " ";
	switch (_suite)
	{
	case Hearts:
		std::cout << "Hearts" << std::endl;
		break;
	case Spades:
		std::cout << "Spades" << std::endl;
		break;
	case Diamonds:
		std::cout << "Diamonds" << std::endl;
		break;
	case Clubs:
		std::cout << "Clubs" << std::endl;
		break;
	default:
		break;
	}
}

int Card::getValue()
{
	return _value;
}

std::string Card::getName()
{
	return _name;
}

void Card::changeCardValue(int value)
{
	_value = value;
}



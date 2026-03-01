#ifndef CARD_H
#define CARD_H

#include <string>

// Suit Definition
enum class Suit {
	None,
	Hearts,
	Diamonds,
	Clubs,
	Spades
};

// Rank Definition
enum class Rank {
	Joker, Ace,   Two,  Three, Four, Five,  Six,
	Seven, Eight, Nine, Ten,   Jack, Queen, King
};

// Card data
struct Card {
	Rank rank;
	Suit suit;
	
	// Constructor
	Card(Rank r, Suit s);
	
	// print card (using toString
	void printCard();


	// String representation
	std::string toString();
};

#endif

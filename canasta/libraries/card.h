#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:		
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

	// Constructor
	Card(Rank r, Suit s);

	// Getters (read-only)
	Rank getRank() const;
	Suit getSuit() const;
		
	std::string toString() const;
	void printCard() const;
	
private:
	const Rank rank_;
	const Suit suit_;
};		
#endif

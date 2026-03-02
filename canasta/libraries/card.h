#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:		
	// Suit Definition
	enum class Suit { None, Hearts, Diamonds, Clubs, Spades, Count };

	// Rank Definition
	enum class Rank {
		Joker, Ace,   Two,  Three, Four, Five,  Six,
		Seven, Eight, Nine, Ten,   Jack, Queen, King,
		Count
	};

	static constexpr size_t RANK_SIZE = static_cast<size_t>(Rank::Count);
	static constexpr size_t SUIT_SIZE = static_cast<size_t>(Suit::Count);

	// Constructor
	explicit Card(Rank r, Suit s);

	// Getters (read-only)
	Rank getRank() const;
	Suit getSuit() const;
		
	// Diagnostics
	std::string toString() const;
	void printCard(const std::string& seperator="\n") const;
	
private:
	const Rank rank_;
	const Suit suit_;
};		

#endif

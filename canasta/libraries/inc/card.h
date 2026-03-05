#ifndef CARD_H
#define CARD_H

#include <string>
#include <array>
#include <cstddef>

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

	// Size for suit/rank
	static constexpr size_t RANK_SIZE = static_cast<size_t>(Rank::Count);
	static constexpr size_t SUIT_SIZE = static_cast<size_t>(Suit::Count);

	// All Ranks
	static constexpr std::array<Rank, RANK_SIZE> AllRanks {
		Rank::Ace,   Rank::Two,   Rank::Three, Rank::Four, Rank::Five,  Rank::Six, Rank::Seven, 
		Rank::Eight, Rank::Nine,  Rank::Ten,   Rank::Jack, Rank::Queen, Rank::King, Rank::Joker
	};

	// All suits
	inline static constexpr std::array<Suit, SUIT_SIZE> AllSuits {
		Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades, Suit::None
	};

	// Constructor
	explicit Card(Rank r, Suit s);

	// Getters (read-only)
	Rank getRank() const;
	Suit getSuit() const;
		
	// Diagnostics
	std::string toString() const;
	void printCard(const std::string& seperator="\n") const;
	
private:
	Rank rank_;
	Suit suit_;
};		

constexpr std::array<Card::Rank, Card::RANK_SIZE> Card::AllRanks;
constexpr std::array<Card::Suit, Card::SUIT_SIZE> Card::AllSuits;

#endif

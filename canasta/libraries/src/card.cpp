#include <array>
#include <iostream>

#include "card.h"

// Constructor
Card::Card(Rank r, Suit s) 
    : rank_(r), 
      suit_(r == Rank::Joker ? Suit::None : s) {}

// Rank Getter
Card::Rank Card::getRank() const { return rank_; }

// Suit Getter
Card::Suit Card::getSuit() const { return suit_; }

// Print the card contents
void Card::printCard(const std::string& seperator) const { std::cout << toString() << seperator; }

// This toStrings the card in the format
// Uses string/array stdlibc++
std::string Card::toString() const {

	static constexpr std::array<const char*, RANK_SIZE> rankStr {
		"[JR", "[ A", "[ 2", "[ 3", "[ 4", "[ 5", "[ 6",
		"[ 7", "[ 8", "[ 9", "[10", "[ J", "[ Q", "[ K"
	};

	static constexpr std::array<const char*, SUIT_SIZE> suitStr {
		u8"\u2605]", u8"\u2665]", u8"\u2666]", u8"\u2663]", u8"\u2660]"
	};
	
	return std::string(rankStr[static_cast<int>(getRank())]) + " " + std::string(suitStr[static_cast<int>(getSuit())]);
}

#include <array>
#include <iostream>

#include "card.h"

// Constructor
Card::Card(Rank r, Suit s) 
    : rank_(r), 
      suit_(r == Rank::Joker ? Suit::None : s) {}

// Rank Getter
Card::Rank Card::getRank() const {
	return rank_;
}

// Suit Getter
Card::Suit Card::getSuit() const {
	return suit_;
}

// Print the card contents
void Card::printCard() const {
	std::cout << toString();
}


// This toStrings the card in the format
// [Card]       Rank of Suit
// Uses string/array stdlibc++
std::string Card::toString() const {

	std::string cardToString = "[Card]\t";

	cardToString += std::array<std::string, 14>{
		"Joker", "Ace",   "Two",  "Three", "Four", "Five",  "Six",
		"Seven", "Eight", "Nine", "Ten",   "Jack", "Queen", "King"
	}[static_cast<int>(rank_)];

	if (rank_ == Rank::Joker) {
		return cardToString + "\n";
	} else {
		return cardToString + " of " + std::array<std::string, 5>{
			"None", "Hearts", "Diamonds", "Clubs", "Spades"
		}[static_cast<int>(suit_)] + "\n";
	}
}

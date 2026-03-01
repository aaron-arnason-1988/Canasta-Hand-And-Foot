#include "card.h"
#include <array>
#include <iostream>

// Constructor
Card::Card(Rank r, Suit s) {
	rank = r;
	
	if (r == Rank::Joker) {
		suit = Suit::None;
	} else {
		suit = s;
	}	
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
	}[static_cast<int>(rank)];

	if (rank == Rank::Joker) {
		return cardToString + "\n";
	} else {
		return cardToString + " of " + std::array<std::string, 5>{
			"None", "Hearts", "Diamonds", "Clubs", "Spades"
		}[static_cast<int>(suit)] + "\n";
	}
}

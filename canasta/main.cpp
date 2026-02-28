#include <iostream>
#include <string>
#include <array>

// Card data (Standard)
// Suit Definition
enum class Suit { None, Hearts, Diamonds, Clubs, Spades };

// Rank Definition
enum class Rank { 
	Joker, Ace,   Two,  Three, Four, Five,  Six,
	Seven, Eight, Nine, Ten,   Jack, Queen, King
};

// Card data
struct Card {
	Rank rank;
	Suit suit;

	Card(Rank r, Suit s) {
		if (r == Rank::Joker) {
			suit = Suit::None;
		} else {
			suit = s;
		}
		rank = r;
	}

	// This toStrings the card in the format
	// [Card]	Rank of Suit
	// Uses string/array stdlibc++
	std::string toString() const {

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
};


int main() {
	Card c(Rank::Joker, Suit::None);
	Card c2(Rank::Ace, Suit::Hearts);
	Card s4(Rank::Four, Suit::Spades);
	Card c9(Rank::Nine, Suit::Clubs);

	std::cout << c.toString();
	std::cout << c2.toString();
	std::cout << s4.toString();
	std::cout << c9.toString();
	return 0;
}

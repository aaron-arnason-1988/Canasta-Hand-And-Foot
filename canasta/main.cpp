#include <iostream>

// Card data (Standard)
// Suit Definition
enum class Suit { None, Hearts, Diamond, Clubs, Spades };

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

	std::string toString() const {
		std::string rankString;
		std::string suitString;

		static const std::string rankStrings[] = {
			"Joker", "Ace",   "Two",  "Three", "Four", "Five",  "Six",
			"Seven", "Eight", "Nine", "Ten",   "Jack", "Queen", "King"
		};
		static const std::string suitStrings[] = {
			"None", "Hearts", "Diamonds", "Clubs", "Spades"
		};



		int rankIndex = static_cast<int>(rank);
		int suitIndex = static_cast<int>(suit);

		if (rank == Rank::Joker) return rankStrings[rankIndex];
		return rankStrings[rankIndex] + " of " + suitStrings[suitIndex] + "\n";
	}
};


int main() {
	Card c(Rank::Ace, Suit::Spades);


	std::cout << c.toString() << "\n";
	return 0;
}

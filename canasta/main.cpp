#include <vector>
#include <array>

#include "libraries/card.h"	// -I libraries if only #include "card.h"


int main() {

	// This represents a deck of cards
	std::vector<Card> deck;
	
	// This is an array representing all possible ranks
	constexpr std::array<Card::Rank, 13> allRanks {
		Card::Rank::Ace,  Card::Rank::Two, Card::Rank::Three, Card::Rank::Four,
		Card::Rank::Five, Card::Rank::Six, Card::Rank::Seven, Card::Rank::Eight,
		Card::Rank::Nine, Card::Rank::Ten, Card::Rank::Jack,  Card::Rank::Queen, 
		Card::Rank::King
	};

	// This is an array representing all possible suits
	constexpr std::array<Card::Suit, 4> allSuits {
		Card::Suit::Hearts, Card::Suit::Clubs, Card::Suit::Diamonds, Card::Suit::Spades
	};


	// Each set of cards has 13 ranks and 4 suits, this creates 52 cards
	for (auto suit : allSuits) {
		for (auto rank : allRanks) {
			deck.emplace_back(rank, suit);
		}
	}

	// Each set of cards requires 2 jokers.
	for (int i = 0; i < 2; i++) {
		deck.emplace_back(Card::Rank::Joker, Card::Suit::None);
	}


	// This prints every card added to the deck
	for (Card& c : deck) {

		if (c.getRank() == Card::Rank::King) {
			c.printCard();
		} else {
			c.printCard(" ");
		}
	}

	return 0;
}

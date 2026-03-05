#include <algorithm>
#include "deck.h"

Deck::Deck(int numberDecks) : rng(std::random_device{}()) { reset(numberDecks); }


void Deck::reset(int numberDecks) {
	cards.clear();

	for (int deckCount = 0; deckCount < numberDecks; deckCount++) {
		for (auto suit : Card::AllSuits) {
			if (suit == Card::Suit::None) { continue; }
			for (auto rank : Card::AllRanks) {
				if (rank == Card::Rank::Joker) { continue; }
				cards.emplace_back(rank, suit);
			}
		}		
	}

	for (int joker = 0; joker < 2; joker++) {
		cards.emplace_back(Card::Rank::Joker, Card::Suit::None);
	}
}


void Deck::shuffle() {
	static std::mt19937 rng(std::random_device{}());	// Random number generator
	std::shuffle(cards.begin(), cards.end(), rng);		// Fisher-Yates algorithm
}


std::optional<Card> Deck::popCard() {
	if (cards.empty()){
		return std::nullopt;
	}

	Card draw = cards.back();
	cards.pop_back();
	return draw;
}


void Deck::printDeck() const {

	// Loop through all the cards, every suit print new line.
	int i = 1;
	for (const Card& c : cards) {
		if (i % 10 == 0) {
			c.printCard();
		} else {
			c.printCard(" ");
		}
		i++;
	}
}

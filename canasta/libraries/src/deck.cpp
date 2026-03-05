#include "deck.h"

Deck::Deck(size_t numberDecks) {

	// This for loop creates NumberDecks decks (default 1)
	for (int deckCount = 0; deckCount < numberDecks; deckCount++) {

		// This creates standard 52 card set
		for (auto suit : Card::AllSuits) {
			if (suit == Card::Suit::None) { continue; }
			for (auto rank : Card::AllRanks) {
				if (rank == Card::Rank::Joker) { continue; }
				deck_.emplace_back(rank, suit);
			}
		}

		// This creates 2 jokers per deck
		for (int joker = 0; joker < 2; joker++) {
			deck_.emplace_back(Card::Rank::Joker, Card::Suit::None);
		}
	}
}


void Deck::shuffle() {
	return;
}

std::optional<Card> Deck::drawCard() {
	if (deck_.empty()){
		return std::nullopt;
	}
	
	Card draw = deck_.back();
	deck_.pop_back();
	return draw;
}


void Deck::printDeck() const {

	// Loop through all the cards, every suit print new line.
	for (const Card& c : deck_) {
		if (c.getRank() == Card::Rank::King) {
			c.printCard();
		} else {
			c.printCard(" ");
		}
	}
}

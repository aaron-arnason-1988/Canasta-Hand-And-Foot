#include <algorithm>
#include "deck.hpp"

namespace CanastaGameEngine {

	Deck::Deck(int numberDecks) : rng(std::random_device{}()) { reset(numberDecks); }


	void Deck::reset(int numberDecks) {
		cards.clear();

		for (int deckCount = 0; deckCount < numberDecks; deckCount++) {
			for (auto suit : CanastaGameEngine::Card::AllSuits) {
				if (suit == CanastaGameEngine::Card::Suit::None) { continue; }
				for (auto rank : CanastaGameEngine::Card::AllRanks) {
					if (rank == CanastaGameEngine::Card::Rank::Joker) { continue; }
					cards.emplace_back(rank, suit);
				}
			}		
		}

		for (int joker = 0; joker < 2; joker++) {
			cards.emplace_back(CanastaGameEngine::Card::Rank::Joker, CanastaGameEngine::Card::Suit::None);
		}
	}


	void Deck::shuffle() {
		static std::mt19937 rng(std::random_device{}());	// Random number generator
		std::shuffle(cards.begin(), cards.end(), rng);		// Fisher-Yates algorithm
	}


	std::optional<CanastaGameEngine::Card> Deck::popCard() {
		if (cards.empty()){
			return std::nullopt;
		}

		CanastaGameEngine::Card draw = cards.back();
		cards.pop_back();
		return draw;
	}


	void Deck::printDeck() const {

		// Loop through all the cards, every suit print new line.
		int i = 1;
		for (const CanastaGameEngine::Card& c : cards) {
			if (i % 10 == 0) {
				c.printCard();
			} else {
				c.printCard(" ");
			}
			i++;
		}
	}

}
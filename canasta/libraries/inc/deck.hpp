#ifndef DECK_H
#define DECK_H

#include <vector>
#include <optional>
#include <random>

#include "card.hpp"

namespace CanastaGameEngine {

	class Deck {
	public:
		explicit Deck(int numberDecks=1);
		void reset(int numberDecks=1);
		void shuffle();
		std::optional<CanastaGameEngine::Card> popCard();
		void printDeck() const;
	private:
		std::vector<CanastaGameEngine::Card> cards;
		std::mt19937 rng;
	};
}
#endif

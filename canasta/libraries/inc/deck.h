#ifndef DECK_H
#define DECK_H

#include <vector>
#include <optional>
#include <random>
#include "card.h"

class Deck {
public:
	explicit Deck(int numberDecks=1);
	void reset(int numberDecks=1);
	void shuffle();
	std::optional<Card> popCard();
	void printDeck() const;
private:
	std::vector<Card> cards;
	std::mt19937 rng;
};

#endif

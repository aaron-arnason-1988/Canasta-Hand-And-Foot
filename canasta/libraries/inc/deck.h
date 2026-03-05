#ifndef DECK_H
#define DECK_H

#include <vector>
#include <optional>
#include "card.h"

class Deck {
public:
	explicit Deck(size_t numberDecks=1);
	void shuffle();
	std::optional<Card> drawCard();
	void printDeck() const;
private:
	std::vector<Card> deck_;
};

#endif

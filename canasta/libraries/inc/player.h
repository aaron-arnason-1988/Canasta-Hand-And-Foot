#ifndef PLAYER_H
#define PLAYER_H

#include <deque>
#include <optional>
#include "card.h"

class Player {
public:
	explicit Player();

	void addCard(const Card& card);
	std::optional<Card> playCard();
	void printHand() const;
private:
	std::deque<Card> hand;
};

#endif

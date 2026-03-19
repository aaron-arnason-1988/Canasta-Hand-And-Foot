#include "player.h"

/* Implement simple war game first. */

Player::Player() : hand() {}


void Player::addCard(const Card& card) {
	hand.push_back(card);
}

std::optional<Card> Player::playCard() {
	if (hand.empty()) {
		return std::nullopt;
	}

	Card play = hand.front();
	hand.pop_front();
	return play;
}

void Player::printHand() const {
	for (const Card& c : hand) {
		c.printCard(" ");
	}
}

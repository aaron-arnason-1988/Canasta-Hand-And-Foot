#include "player.hpp"

/* Implement simple war game first. */
namespace CanastaGameEngine {

	Player::Player() : hand() {}


	void Player::addCard(const CanastaGameEngine::Card& card) {
		hand.push_back(card);
	}

	std::optional<CanastaGameEngine::Card> Player::playCard() {
		if (hand.empty()) {
			return std::nullopt;
		}

		CanastaGameEngine::Card play = hand.front();
		hand.pop_front();
		return play;
	}

	const std::deque<CanastaGameEngine::Card>& Player::getHand() const {
		return hand;
	};

	void Player::printHand() const {
		for (const CanastaGameEngine::Card& c : hand) {
			c.printCard(" ");
		}
	}

}
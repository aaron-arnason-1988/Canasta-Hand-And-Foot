#ifndef PLAYER_H
#define PLAYER_H

#include <deque>
#include <optional>
#include "card.hpp"

namespace CanastaGameEngine {

	class Player {
	public:
		explicit Player();

		void addCard(const CanastaGameEngine::Card& card);
		std::optional<CanastaGameEngine::Card> playCard();
		const std::deque<CanastaGameEngine::Card>& getHand() const;
		void printHand() const;
	private:
		std::deque<CanastaGameEngine::Card> hand;
	};

}
#endif

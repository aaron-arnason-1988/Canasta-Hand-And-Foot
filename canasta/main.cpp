#include "deck.h"

int main() {

	Deck d(1);

	for (int i = 0; i < 100; i++) {
		
		auto cardOpt = d.drawCard();
		if (cardOpt) {
			Card c = *cardOpt;
			if (c.getRank() == Card::Rank::Joker) {
				c.printCard("\n");
			} else if (c.getRank() == Card::Rank::Ace) {
				c.printCard("\n");
			}
			else {
				c.printCard(" ");
			}
		}
	}

	return 0;
}

#include <iostream>
#include <string>
#include <array>
#include "libraries/card.h"	// -I libraries if only #include "card.h"




int main() {
	Card c(Rank::Joker, Suit::None);
	Card c2(Rank::Ace, Suit::Hearts);
	Card s4(Rank::Four, Suit::Spades);
	Card c9(Rank::Nine, Suit::Clubs);

	c.printCard();
	c2.printCard();
	s4.printCard();
	c9.printCard();

	return 0;
}

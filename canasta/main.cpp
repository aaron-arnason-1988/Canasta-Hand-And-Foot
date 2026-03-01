#include "libraries/card.h"	// -I libraries if only #include "card.h"


int main() {
	Card c(Card::Rank::Joker, Card::Suit::None);
	Card c2(Card::Rank::Ace, Card::Suit::Hearts);
	Card s4(Card::Rank::Four, Card::Suit::Spades);
	Card c9(Card::Rank::Nine, Card::Suit::Clubs);

	c.printCard();
	c2.printCard();
	s4.printCard();
	c9.printCard();

	return 0;
}

#include "deck.h"
#include "player.h"
#include <iostream>

int main() {

	Player p1;
	Player p2;

	Deck d(1);

	d.shuffle();	
//	d.printDeck();

	// deal cards.
	for (int i = 0; i < 54; i++) {
		auto cardOpt = d.popCard();
		if (cardOpt) {
			if (i % 2 == 0) {
				p2.addCard(*cardOpt);
			} else {
				p1.addCard(*cardOpt);
			}
		}
	}


	p1.printHand();
	std::cout << std::endl;

	for (int i = 0; i < 1; i++)
	{
		auto w1Opt = p1.playCard();
		auto w2Opt = p2.playCard();

		std::cout << std::endl << std::endl;
		w1Opt->printCard(" <= p1 | ");
		w2Opt->printCard(" <= p2");
		std::cout << std::endl;

		// game logic
		if (w2Opt->getRank() < w1Opt->getRank()) {
			std::cout << "p1 card higher" << std::endl;
		} else if (w2Opt->getRank() > w1Opt->getRank()) {
			std::cout << "p2 card higher" << std::endl;
		} else {
			std::cout << "WAR" << std::endl;
		}
	}

	//p2.playCard()->printCard();

	// print current hand
	std::cout << std::endl << "Player 1" << std::endl;
	p1.printHand();

	std::cout << std::endl << "Player 2" << std::endl;
	p2.printHand();

	std::cout << std::endl;

	return 0;
}

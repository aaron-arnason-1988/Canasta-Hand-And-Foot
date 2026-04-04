#include <iostream>
#include <vector>

#include "deck.hpp"
#include "player.hpp"

int main() {

	CanastaGameEngine::Player p1;
	CanastaGameEngine::Player p2;

	std::vector<CanastaGameEngine::Player *> players = { &p1, &p2 };

	// Shuffles the deck
	CanastaGameEngine::Deck d(1);
	d.shuffle();

	// Add cards to each player.
	auto playerIterator = players.begin();
	while (auto cardOpt = d.popCard()) {
		(*playerIterator)->addCard(*cardOpt);
		if (++playerIterator == players.end()) {
			playerIterator = players.begin();
		}
	}

	/*
	// Loops through player 1 hand, and prints it
	for (const CanastaGameEngine::Card& card : p1.getHand()) {
		card_view c2 = card.generateCardView();
		render_selected_card(&c2);
		//sleep(1);
	}

	// Loops through player 2 hand, and prints it
	for (const CanastaGameEngine::Card& card : p2.getHand()) {
		card_view c2 = card.generateCardView();
		render_selected_card(&c2);
		//sleep(1);
	}
	*/

	// This loops through, plays war for p1/p2 cards
	//for (int i = 0; i < 26; i++)
	while(true)
	{
		// Grab card
		auto w1Opt = p1.playCard();
		auto w2Opt = p2.playCard();

		if (!w1Opt || !w2Opt) { break; }

		// p1/p2 cards
		std::cout << std::endl << std::endl;
		w1Opt->printCard(" <= p1 | ");
		w2Opt->printCard(" <= p2");
		std::cout << std::endl;


		card_view c2;

		// game logic
		if (w2Opt->getRank() < w1Opt->getRank()) {
			c2 = w1Opt->generateCardView();
		} else if (w2Opt->getRank() > w1Opt->getRank()) {
			c2 = w2Opt->generateCardView();
		} else {
			std::cout << "WAR" << std::endl;
		}

		render_selected_card(&c2);

		sleep(1);
	}

	return 0;
}

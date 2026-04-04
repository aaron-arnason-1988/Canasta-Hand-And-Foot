#ifndef CARD_H
#define CARD_H

#include <string>
#include <array>
#include <cstddef>

// This is the C/C++ interface. Card rendering (UI) is done 
// in C. All game logic, players/cards/decks/hands etc are c++
#include "../../renderer/common_card.h"

namespace CanastaGameEngine {

	class Card {
	public:	
		
		// Suit Definition (attaches C++ = C enum)
		enum class Suit : int { 
			None     = Common_None, 
			Hearts   = Common_Hearts, 
			Diamonds = Common_Diamonds, 
			Clubs    = Common_Clubs, 
			Spades   = Common_Spades, 
			Count 
		};

		// Rank Definition (attaches C++ = C enum)
		enum class Rank : int {
			Joker = Common_Joker, 
			Ace   = Common_Ace,   
			Two   = Common_Two,  
			Three = Common_Three, 
			Four  = Common_Four, 
			Five  = Common_Five,  
			Six   = Common_Six,
			Seven = Common_Seven, 
			Eight = Common_Eight, 
			Nine  = Common_Nine, 
			Ten   = Common_Ten,   
			Jack  = Common_Jack, 
			Queen = Common_Queen, 
			King  = Common_King,
			Count
		};

		// Size for suit/rank
		static constexpr size_t RANK_SIZE = static_cast<size_t>(Rank::Count);
		static constexpr size_t SUIT_SIZE = static_cast<size_t>(Suit::Count);

		// All Ranks
		static constexpr std::array<Rank, RANK_SIZE> AllRanks {
			Rank::Ace,   Rank::Two,   Rank::Three, Rank::Four, Rank::Five,  Rank::Six, Rank::Seven, 
			Rank::Eight, Rank::Nine,  Rank::Ten,   Rank::Jack, Rank::Queen, Rank::King, Rank::Joker
		};

		// All suits
		inline static constexpr std::array<Suit, SUIT_SIZE> AllSuits {
			Suit::Hearts, Suit::Diamonds, Suit::Clubs, Suit::Spades, Suit::None
		};

		// Constructor
		explicit Card(Rank r, Suit s);

		// Getters (read-only)
		Rank getRank() const;
		Suit getSuit() const;
			
		// Diagnostics
		std::string toString() const;
		void printCard(const std::string& seperator="\n") const;

		// Helper to translate cpp object to C struct for rendering to screen 
		inline card_view generateCardView() const {
			return {
				static_cast<Ranks>(getRank()),
				static_cast<Suits>(getSuit())
			};
		}
		
	private:
		Rank rank_;
		Suit suit_;
	};		

	constexpr std::array<Card::Rank, Card::RANK_SIZE> Card::AllRanks;
	constexpr std::array<Card::Suit, Card::SUIT_SIZE> Card::AllSuits;


}

#endif

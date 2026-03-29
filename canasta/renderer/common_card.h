#ifndef COMMON_CARD_H
#define COMMON_CARD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef enum _suit { Common_None, Common_Hearts, Common_Diamonds, Common_Clubs, Common_Spades } Suits;
typedef enum _rank {
	Common_Joker, 
	Common_Ace,
    Common_Two,
	Common_Three, 
	Common_Four, 
	Common_Five,  
	Common_Six,
	Common_Seven, 
	Common_Eight, 
	Common_Nine, 
	Common_Ten,
    Common_Jack, 
	Common_Queen, 
	Common_King
} Ranks;

typedef struct _card_view {
	Ranks rank;
	Suits suit;
} card_view;

void render_selected_card(card_view *cv);

#ifdef __cplusplus
}
#endif

#endif

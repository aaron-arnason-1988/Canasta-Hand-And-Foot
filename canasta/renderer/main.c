#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define SUIT_COUNT   5
#define RANK_COUNT  14

// enum is used for accessing index of suit_symbol to generate correct symbol for playing card
// char ** is simply the character to print✯
typedef enum _suit { None, Hearts, Diamonds, Clubs, Spades } Suit;
char *suit_symbols[] = {"✪", "♥", "♦", "♣", "♠"};

typedef enum _rank {
	Joker, Ace,   Two,  Three, Four, Five,  Six,
	Seven, Eight, Nine, Ten,   Jack, Queen, King
} Rank;
char *rank_symbols[] = {"JR", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};


// Represents the card symbol to be printed at top left and bottom right of each card
typedef struct _card_view {
	Rank rank;
	Suit suit;	
} card_view;


void print_card_view(card_view cv) {
	
	// Ensure the rank and suit are in bounds.
	if (cv.rank < RANK_COUNT && cv.suit < SUIT_COUNT) 
	{
		printf("Rank: %s\tSuit: %s\n", rank_symbols[cv.rank], suit_symbols[cv.suit]);
	} else 
	{
		printf("Card outside of range\n");
	}
}


#define UTF8_BYTE_SIZE 3
const char *trbl_corner =       "▚";
const char *tlbr_corner =       "▞";
const char *bottom_horizontal = "▄";
const char *top_horizontal =    "▀";
const char *left_vertical =     "▌";
const char *right_vertical =    "▐";


typedef struct card_to_render {
	char top_border_row[58];
	char top_rank_row[24];
	char top_suit_row[26];
	char blank_row[24];
	char middle_suit_row[26];
	char bottom_suit_row[26];
	char bottom_rank_row[24];
	char bottom_border_row[58];

	card_view card_data;
} renderable_card;

void initialize_renderable_card(renderable_card *ctr);
void set_border(renderable_card *ctr);
void set_rank(renderable_card *ctr);
void set_suit(renderable_card *ctr);
void set_blank(renderable_card *ctr);
void render_card(renderable_card *ctr);
void render_selected_card(renderable_card *ctr, Rank r, Suit s);


void initialize_renderable_card(renderable_card *ctr) {
	set_border(ctr);
	set_rank(ctr);
	set_suit(ctr);
	set_blank(ctr);
}

void set_border(renderable_card *ctr) {
	memset(ctr->top_border_row, 0, sizeof(ctr->top_border_row));
	memset(ctr->bottom_border_row, 0, sizeof(ctr->bottom_border_row));

	// Set top border
	strncat(ctr->top_border_row, tlbr_corner, UTF8_BYTE_SIZE);
	for (int i = 0; i < 17; i++) {
		strncat(ctr->top_border_row, top_horizontal, UTF8_BYTE_SIZE);
	}
	strncat(ctr->top_border_row, trbl_corner, UTF8_BYTE_SIZE);
	ctr->top_border_row[57] = '\0';

	// Set bottom border
	strncat(ctr->bottom_border_row, trbl_corner, UTF8_BYTE_SIZE);
	for(int i = 0; i < 17; i++) {
		strncat(ctr->bottom_border_row, bottom_horizontal, UTF8_BYTE_SIZE);
	}
	strncat(ctr->bottom_border_row, tlbr_corner, UTF8_BYTE_SIZE);
	ctr->bottom_border_row[57] = '\0';
}

void set_rank(renderable_card *ctr) {
	memset(ctr->top_rank_row, 0, sizeof(ctr->top_rank_row));
	memset(ctr->bottom_rank_row, 0, sizeof(ctr->bottom_rank_row));

	// Top rank
	strncat(ctr->top_rank_row, left_vertical, UTF8_BYTE_SIZE);
	int trl = strlen(rank_symbols[ctr->card_data.rank]);
	strncat(ctr->top_rank_row, rank_symbols[ctr->card_data.rank], trl);
	memset(ctr->top_rank_row + UTF8_BYTE_SIZE + trl, ' ', 17 - trl);
	strncat(ctr->top_rank_row, right_vertical, UTF8_BYTE_SIZE);
	ctr->top_rank_row[23] = '\0';

	// Bottom rank
	strncat(ctr->bottom_rank_row, left_vertical, UTF8_BYTE_SIZE);
	memset(ctr->bottom_rank_row + UTF8_BYTE_SIZE, ' ', 17 - trl);
	strncat(ctr->bottom_rank_row, rank_symbols[ctr->card_data.rank], trl);
	strncat(ctr->bottom_rank_row, right_vertical, UTF8_BYTE_SIZE);
	ctr->bottom_rank_row[23] = '\0';
}

void set_suit(renderable_card *ctr) {
	memset(ctr->top_suit_row, 0, sizeof(ctr->top_suit_row));
	memset(ctr->middle_suit_row, 0, sizeof(ctr->middle_suit_row));
	memset(ctr->bottom_suit_row, 0, sizeof(ctr->bottom_suit_row));
	
	// Top suit
	strncat(ctr->top_suit_row, left_vertical, UTF8_BYTE_SIZE);
	int tsl = strlen(suit_symbols[ctr->card_data.suit]);
	strncat(ctr->top_suit_row + UTF8_BYTE_SIZE, suit_symbols[ctr->card_data.suit], tsl);
	memset(ctr->top_suit_row + UTF8_BYTE_SIZE + tsl, ' ', 19 - tsl);
	strncat(ctr->top_suit_row, right_vertical, UTF8_BYTE_SIZE);
	ctr->top_suit_row[25] = '\0';

	// This sets middle suit TODO: mimic how cards actually show in the middle
	strncat(ctr->middle_suit_row, left_vertical, UTF8_BYTE_SIZE);
	memset(ctr->middle_suit_row + UTF8_BYTE_SIZE, ' ', 8);
	strncat(ctr->middle_suit_row + UTF8_BYTE_SIZE + 8, suit_symbols[ctr->card_data.suit], tsl);
	memset(ctr->middle_suit_row + UTF8_BYTE_SIZE + tsl + 8, ' ', 8);
	strncat(ctr->middle_suit_row + UTF8_BYTE_SIZE + tsl, right_vertical, UTF8_BYTE_SIZE);
	ctr->middle_suit_row[25] = '\0';
	// TODO: mimic how cards actually show in the middle (pattern)


	// Bottom suit
	strncat(ctr->bottom_suit_row, left_vertical, UTF8_BYTE_SIZE);
	memset(ctr->bottom_suit_row + UTF8_BYTE_SIZE, ' ', 19 - tsl);
	strncat(ctr->bottom_suit_row + UTF8_BYTE_SIZE + tsl, suit_symbols[ctr->card_data.suit], tsl);
	strncat(ctr->bottom_suit_row, right_vertical, UTF8_BYTE_SIZE);	
	ctr->bottom_suit_row[25] = '\0';
}

void set_blank(renderable_card *ctr) {
	memset(ctr->blank_row, 0, sizeof(ctr->blank_row));

	strncat(ctr->blank_row, left_vertical, UTF8_BYTE_SIZE);
	memset(ctr->blank_row + UTF8_BYTE_SIZE, ' ', 17);
	strncat(ctr->blank_row, right_vertical, UTF8_BYTE_SIZE);
	ctr->blank_row[23] = '\0';
}

void render_card(renderable_card *ctr) {
	printf("%s\n", ctr->top_border_row);
	printf("%s\n", ctr->top_rank_row);
	printf("%s\n", ctr->top_suit_row);
	printf("%s\n", ctr->blank_row);
	printf("%s\n", ctr->blank_row);
	printf("%s\n", ctr->blank_row);
	printf("%s\n", ctr->middle_suit_row);
	printf("%s\n", ctr->blank_row);
	printf("%s\n", ctr->blank_row);
	printf("%s\n", ctr->blank_row);
	printf("%s\n", ctr->bottom_suit_row);
	printf("%s\n", ctr->bottom_rank_row);
	printf("%s\n", ctr->bottom_border_row);
}




// This function breaks. The rest kinda works. To be debugged
void render_selected_card(renderable_card *ctr, Rank r, Suit s) {
	memset(ctr, 0, sizeof(ctr));
	
	ctr->card_data.rank = r;
	ctr->card_data.suit = s;

	initialize_renderable_card(ctr);

	render_card(ctr);
}

int main(int argc, char **argv) {

	renderable_card display_card = {0};
	renderable_card *ctr = &display_card;
	

	for (int i = 0; i < SUIT_COUNT; i++) {
		for (int j = 0; j < RANK_COUNT; j++) {
			render_selected_card(ctr, j, i);	
			sleep(1);	
		}
	}

	/*
	render_selected_card(ctr, Eight, Clubs);
	render_selected_card(ctr, Nine, Hearts);
	render_selected_card(ctr, Ten, Spades);
	render_selected_card(ctr, Joker, None);
	*/
	



/*
	// Top Border
	char top_border[57] = {0};
	strncat(top_border, tlbr_corner, UTF8_BYTE_SIZE);
	for (int i = 0; i < 17; i++) {
		strncat(top_border, top_horizontal, UTF8_BYTE_SIZE);
	}
	strncat(top_border, trbl_corner, UTF8_BYTE_SIZE);

	// Top Rank
	char top_rank[23] = {0};
	strncat(top_rank, left_vertical, UTF8_BYTE_SIZE);
	
	int trl = strlen(rank_symbols[1]);
	strncat(top_rank, rank_symbols[1], trl);
	memset(top_rank + UTF8_BYTE_SIZE + trl, ' ', 17 - trl);
	strncat(top_rank, right_vertical, UTF8_BYTE_SIZE);

	// Top Suit
	char top_suit[25] = {0};
	strncat(top_suit, left_vertical, UTF8_BYTE_SIZE);
	
	int tsl = strlen(suit_symbols[1]);
	strncat(top_suit + UTF8_BYTE_SIZE, suit_symbols[1], tsl);
	memset(top_suit + UTF8_BYTE_SIZE + tsl, ' ', 19 - tsl);
	strncat(top_suit, right_vertical, UTF8_BYTE_SIZE);
	
	
	// Blank
	char blank_row[23] = {0};
	strncat(blank_row, left_vertical, UTF8_BYTE_SIZE);
	memset(blank_row + UTF8_BYTE_SIZE, ' ', 17);
	strncat(blank_row, right_vertical, UTF8_BYTE_SIZE);
	
	// Suit
	char middle_suit[25] = {0};
	strncat(middle_suit, left_vertical, UTF8_BYTE_SIZE);
	memset(middle_suit + UTF8_BYTE_SIZE, ' ', 8);
	strncat(middle_suit + UTF8_BYTE_SIZE + 8, suit_symbols[1], tsl);
	memset(middle_suit + UTF8_BYTE_SIZE * 2 + 8, ' ', 8);
	strncat(middle_suit, right_vertical, UTF8_BYTE_SIZE);
	

	// Bottom Suit
	char bottom_suit[25] = {0};
	strncat(bottom_suit, left_vertical, UTF8_BYTE_SIZE);
	
	memset(bottom_suit + UTF8_BYTE_SIZE, ' ', 19 - tsl);
	strncat(bottom_suit + UTF8_BYTE_SIZE + tsl, suit_symbols[1], tsl);
	strncat(bottom_suit, right_vertical, UTF8_BYTE_SIZE);	

	// Bottom Rank
	char bottom_rank[23] = {0};
	strncat(bottom_rank, left_vertical, UTF8_BYTE_SIZE);

	memset(bottom_rank + UTF8_BYTE_SIZE, ' ', 17 - trl);
	strncat(bottom_rank, rank_symbols[1], trl);
	strncat(bottom_rank, right_vertical, UTF8_BYTE_SIZE);


	// Bottom Border
	char bottom_border[57] = {0};
	strncat(bottom_border, trbl_corner, UTF8_BYTE_SIZE);
	for(int i = 0; i < 17; i++) {
		strncat(bottom_border, bottom_horizontal, UTF8_BYTE_SIZE);
	}
	strncat(bottom_border, tlbr_corner, UTF8_BYTE_SIZE);


	printf("%s\n", top_border);
	printf("%s\n", top_rank);
	printf("%s\n", top_suit);
	printf("%s\n", blank_row);
	printf("%s\n", blank_row);
	printf("%s\n", blank_row);
	printf("%s\n", middle_suit);
	printf("%s\n", blank_row);
	printf("%s\n", blank_row);
	printf("%s\n", blank_row);
	printf("%s\n", bottom_suit);
	printf("%s\n", bottom_rank);
	printf("%s\n", bottom_border);


	card_view cv;

	cv.rank = Ten;
	cv.suit = Hearts;

	card_view cv2;

	cv2.rank = Joker;
	cv2.suit = None;

	card_view cv3;

	cv3.rank = Jack;
	cv3.suit = Clubs;

	card_view cv4;

	cv4.rank = King + 5;
	cv4.suit = Spades + 3;
	

	print_card_view(cv);
	print_card_view(cv2);
	print_card_view(cv3);
	print_card_view(cv4);
*/
	return 0;
}

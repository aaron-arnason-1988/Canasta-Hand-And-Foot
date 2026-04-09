#ifndef PUBLIC_TERMINAL_UI_H
#define PUBLIC_TERMINAL_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/ioctl.h>	// ioctl() and TIOCGWINSZ
#include <unistd.h>		// STDOUT_FILENO
#include <string.h> 	// memset

#ifndef MAX_COLCOUNT
#define MAX_COLCOUNT 0
#endif

#ifndef MAX_ROWCOUNT
#define MAX_ROWCOUNT 0
#endif

#define TERMINAL_MAX_COLUMNS 	MAX_COLCOUNT
#define TERMINAL_MAX_ROWS		MAX_ROWCOUNT

#define SUIT_COUNT 5
#define RANK_COUNT 14

typedef enum {
	Common_Joker, 			// JR
	Common_Ace,				// A
    Common_Two,				// 2
	Common_Three, 			// 3
	Common_Four, 			// 4
	Common_Five,  			// 5
	Common_Six,				// 6
	Common_Seven, 			// 7
	Common_Eight, 			// 8
	Common_Nine, 			// 9
	Common_Ten,				// 10
    Common_Jack, 			// J
	Common_Queen, 			// Q
	Common_King				// K
} card_ranks_name;

typedef enum {
	Common_None, 			// ✪
	Common_Hearts, 			// ♥
	Common_Diamonds, 		// ♦
	Common_Clubs, 			// ♣
	Common_Spades			// ♠
} card_suits_name;

typedef struct _card_view {
	card_ranks_name rank;
	card_suits_name suit;
} card_view;

typedef struct {
	int rows;
	int columns;
} terminal_dimension;

typedef struct {
	char ch[4];
} cell;


int set_terminal_size(terminal_dimension *wd);          // Public (maybe)

void initialize_frame_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], int rows, int cols);                         // Public
void print_frame_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], int rows, int cols);                              // Public
void clear_frame_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], int rows, int cols);                              // Public
void set_card_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], card_view cv, int x, int y);                      // Public

#ifdef __cplusplus
}
#endif

#endif
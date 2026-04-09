#include "inc/public_terminal_ui.h"

typedef struct {
	void (*init)(cell (*)[TERMINAL_MAX_COLUMNS], int, int);
	void (*load_card)(cell (*)[TERMINAL_MAX_COLUMNS], card_view, int, int);
	void (*display)(cell (*)[TERMINAL_MAX_COLUMNS], int, int);
	void (*clear)(cell (*)[TERMINAL_MAX_COLUMNS], int, int);
} ui;



int main(int argc, char **argv) {
	// Determine terminal shape, and create 2d array frame buffer
	terminal_dimension window_size;
	terminal_dimension *term_dim = &window_size;

	// sets terminal size in terminal_dimension struct.
	if(set_terminal_size(term_dim)) { return -1; }


	ui x;
	x.init = initialize_frame_buffer;
	x.load_card = set_card_in_buffer;
	x.display = print_frame_buffer;
	x.clear = clear_frame_buffer;
	

	// Create array to mimic current size. Set to empty (with null termination)
	cell frame_buffer[term_dim->rows][term_dim->columns];
	//initialize_frame_buffer(frame_buffer, term_dim->rows, term_dim->columns);

	x.init(frame_buffer, term_dim->rows, term_dim->columns);

	x.load_card(frame_buffer, (card_view){ Common_Ace,  Common_Spades}, 1, 327);
	x.load_card(frame_buffer, (card_view){ Common_Two, Common_Diamonds }, 1, 5);
	x.load_card(frame_buffer, (card_view){ Common_King, Common_Clubs }, 1, 10);
	x.load_card(frame_buffer, (card_view){ Common_Two, Common_Spades }, 1, 15);
	x.display(frame_buffer, TERMINAL_MAX_ROWS, TERMINAL_MAX_COLUMNS);
	sleep(1);

	for (int m = 1; m < 327; m++) {
		x.load_card(frame_buffer, (card_view){ Common_Seven, Common_Hearts }, 1, m);
		x.display(frame_buffer, TERMINAL_MAX_ROWS, TERMINAL_MAX_COLUMNS);
		x.clear(frame_buffer, TERMINAL_MAX_ROWS, TERMINAL_MAX_COLUMNS);
		usleep(20000);
	}

	int jk = 0;
	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < SUIT_COUNT; i++) {
			for (int j = 0; j < RANK_COUNT; j++) {
				x.load_card(frame_buffer, (card_view){ j, i }, 3 + jk, (i + 1 + j) * 19);
			}
			jk += 3;
		}
	}

	x.display(frame_buffer, TERMINAL_MAX_ROWS, TERMINAL_MAX_COLUMNS);
	return 0;
}
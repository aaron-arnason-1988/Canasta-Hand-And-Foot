#include "inc/public_terminal_ui.h"

int main(int argc, char **argv) {
	// Determine terminal shape, and create 2d array frame buffer
	terminal_dimension window_size;
	terminal_dimension *term_dim = &window_size;

	// sets terminal size in terminal_dimension struct.
	if(set_terminal_size(term_dim)) { return -1; }

	// Create array to mimic current size. Set to empty (with null termination)
	cell frame_buffer[term_dim->rows][term_dim->columns];
	initialize_frame_buffer(frame_buffer, term_dim->rows, term_dim->columns);

	set_card_in_buffer(frame_buffer, (card_view){ Common_Ace,  Common_Spades}, 1, 327);
	set_card_in_buffer(frame_buffer, (card_view){ Common_Two, Common_Diamonds }, 1, 5);
	set_card_in_buffer(frame_buffer, (card_view){ Common_King, Common_Clubs }, 1, 10);
	set_card_in_buffer(frame_buffer, (card_view){ Common_Two, Common_Spades }, 1, 15);

	for (int m = 1; m < 327; m++) {
		set_card_in_buffer(frame_buffer, (card_view){ Common_Seven, Common_Hearts }, 1, m);
		print_frame_buffer(frame_buffer, TERMINAL_MAX_ROWS, TERMINAL_MAX_COLUMNS);
		clear_frame_buffer(frame_buffer, TERMINAL_MAX_ROWS, TERMINAL_MAX_COLUMNS);
		usleep(20000);
	}

	int jk = 0;
	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < SUIT_COUNT; i++) {
			for (int j = 0; j < RANK_COUNT; j++) {
				set_card_in_buffer(frame_buffer, (card_view){ j, i }, 3 + jk, (i + 1 + j) * 19);
			}
			jk += 3;
		}
	}

	print_frame_buffer(frame_buffer, TERMINAL_MAX_ROWS, TERMINAL_MAX_COLUMNS);
	return 0;
}
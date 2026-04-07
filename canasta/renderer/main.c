#include <sys/ioctl.h>	// ioctl() and TIOCGWINSZ
#include <unistd.h>		// STDOUT_FILENO
#include <string.h> 	// memset

#define TERMINAL_MAX_COLUMNS 	MAX_COLCOUNT
#define TERMINAL_MAX_ROWS		MAX_ROWCOUNT

#define CARD_HEIGHT	13
#define CARD_WIDTH	19

#define SUIT_COUNT 5
#define RANK_COUNT 14

#define OUTPUT_EXTRA_BYTES 10


typedef struct {
	char ch[4];
} cell;

typedef struct {
	int rows;
	int columns;
} terminal_dimension;

typedef enum {
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
} card_ranks_name;

typedef struct {
	cell cells[2];
} card_rank;

static const card_rank card_ranks[] = {
	[Common_Joker] = {
		.cells[0].ch[0] = 'J',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = 'R',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_Ace] = {
		.cells[0].ch[0] = 'A',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = ' ',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_Two] = {
		.cells[0].ch[0] = '2',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = ' ',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_Three] = {
		.cells[0].ch[0] = '3',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = ' ',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_Four] = {
		.cells[0].ch[0] = '4',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = ' ',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_Five] = {
		.cells[0].ch[0] = '5',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = ' ',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_Six] = {
		.cells[0].ch[0] = '6',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = ' ',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_Seven] = {
		.cells[0].ch[0] = '7',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = ' ',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_Eight] = {
		.cells[0].ch[0] = '8',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = ' ',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_Nine] = {
		.cells[0].ch[0] = '9',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = ' ',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_Ten] = {
		.cells[0].ch[0] = '1',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = '0',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_Jack] = {
		.cells[0].ch[0] = 'J',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = ' ',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_Queen] = {
		.cells[0].ch[0] = 'Q',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = ' ',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	},
	[Common_King] = {
		.cells[0].ch[0] = 'K',
		.cells[0].ch[1] = (char)0x00,
		.cells[0].ch[2] = (char)0x00,
		.cells[0].ch[3] = (char)0x00,

		.cells[1].ch[0] = ' ',
		.cells[1].ch[1] = (char)0x00,
		.cells[1].ch[2] = (char)0x00,
		.cells[1].ch[3] = (char)0x00
	}
};

typedef enum {
	Common_None, 			// ✪
	Common_Hearts, 			// ♥
	Common_Diamonds, 		// ♦
	Common_Clubs, 			// ♣
	Common_Spades			// ♠
} card_suits_name;

static const cell card_suits[] = {
	[Common_None] = { // Star
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x9C,
		.ch[2] = (char)0xAA,
		.ch[3] = (char)0x00
	},
	[Common_Hearts] = {// Heart
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x99,
		.ch[2] = (char)0xA5,
		.ch[3] = (char)0x00
	},
	[Common_Diamonds] = {// Diamond
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x99,
		.ch[2] = (char)0xA6,
		.ch[3] = (char)0x00
	},
	[Common_Clubs] = {// Clubs
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x99,
		.ch[2] = (char)0xA3,
		.ch[3] = (char)0x00
	},
	[Common_Spades] = {// Spades
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x99,
		.ch[2] = (char)0xA0,
		.ch[3] = (char)0x00
	}
};

typedef enum {
	TopLeftCorner,			// ▞
	TopRightCorner,			// ▚
	BottomLeftCorner,		// ▚
	BottomRightCorner,		// ▞
	BottomHorizontal,		// ▄
	TopHorizontal,			// ▀
	LeftVertical,			// ▌
	RightVertical,			// ▐
	Empty					//  
} card_component_name;

static const cell card_components[] = {
	[TopLeftCorner] = {// tlbr_corner
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x96,
		.ch[2] = (char)0x9E,
		.ch[3] = (char)0x00
	},
	[TopRightCorner] = {// trbl_corner
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x96,
		.ch[2] = (char)0x9A,
		.ch[3] = (char)0x00
	},
	[BottomLeftCorner] = {// trbl_corner
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x96,
		.ch[2] = (char)0x9A,
		.ch[3] = (char)0x00
	},
	[BottomRightCorner] = {// tlbr_corner
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x96,
		.ch[2] = (char)0x9E,
		.ch[3] = (char)0x00
	},
	[BottomHorizontal] = {// bottom_horizontal
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x96,
		.ch[2] = (char)0x84,
		.ch[3] = (char)0x00
	},
	[TopHorizontal] = {// top_horizontal
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x96,
		.ch[2] = (char)0x80,
		.ch[3] = (char)0x00
	},
	[LeftVertical] = {// left_vertical
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x96,
		.ch[2] = (char)0x8C,
		.ch[3] = (char)0x00
	}, 
	[RightVertical] = {// right_vertical
		.ch[0] = (char)0xE2,
		.ch[1] = (char)0x96,
		.ch[2] = (char)0x90,
		.ch[3] = (char)0x00
	},
	[Empty] = {// Spades
		.ch[0] = ' ',
		.ch[1] = '\0',
		.ch[2] = '\0',
		.ch[3] = '\0'
	}
};


typedef struct _card_view {
	card_ranks_name rank;
	card_suits_name suit;
} card_view;


void show_cursor();
void hide_cursor();
void set_terminal_size(terminal_dimension *wd);
void print_frame_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], int rows, int cols);
void initialize_frame_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], int rows, int cols);
void set_component_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], cell component, int row, int col);
void clear_frame_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], int rows, int cols);


void set_card_border_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], int x, int y) {
	const int ROW_WIDTH = 17;
	const int MIDDLE_ROWS = 11;

	int i = 0;	// Changes for each column
	int j = 0;	// Changes after each row

	// Top Border
	i = 0;	// changes after each column
	set_component_in_buffer(fb, card_components[TopLeftCorner], x + j, y + i);
	for (i = 1; i < ROW_WIDTH; i++) { set_component_in_buffer(fb, card_components[TopHorizontal], x + j, y + i); }
	set_component_in_buffer(fb, card_components[TopRightCorner], x + j, y + i);

	// 3 blank rows
	for (int k = 0; k < MIDDLE_ROWS; k++) {
		// Blank Row ****
		j++;
		i = 0;
		set_component_in_buffer(fb, card_components[LeftVertical], x + j, y + i);
		for (i = 1; i < ROW_WIDTH; i++) { set_component_in_buffer(fb, card_components[Empty], x + j, y + i); }
		set_component_in_buffer(fb, card_components[RightVertical], x + j, y + i);
	}

	// Bottom Border
	j++;
	i = 0;
	set_component_in_buffer(fb, card_components[BottomLeftCorner], x + j, y + i);
	for (i = 1; i < ROW_WIDTH; i++) { set_component_in_buffer(fb, card_components[BottomHorizontal], x + j, y + i); }
	set_component_in_buffer(fb, card_components[BottomRightCorner], x + j, y + i);
}

void set_card_view_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], card_view cv, int x, int y) {

	// Set top left rank
	set_component_in_buffer(fb, card_ranks[cv.rank].cells[0], x + 1, y + 1);
	set_component_in_buffer(fb, card_ranks[cv.rank].cells[1], x + 1, y + 2);

	// Set top left suit
	set_component_in_buffer(fb, card_suits[cv.suit], x + 2, y + 1);

	// Set middle suit
	set_component_in_buffer(fb, card_suits[cv.suit], x + 6, y + 8);

	// set bottom right suit
	set_component_in_buffer(fb, card_suits[cv.suit], x + 10, y + 16);

	// set bottom right rank
	if (cv.rank == Common_Ten || cv.rank == Common_Joker) {
		set_component_in_buffer(fb, card_ranks[cv.rank].cells[0], x + 11, y + 15);
		set_component_in_buffer(fb, card_ranks[cv.rank].cells[1], x + 11, y + 16);
	} else {
		set_component_in_buffer(fb, card_ranks[cv.rank].cells[1], x + 11, y + 15);
		set_component_in_buffer(fb, card_ranks[cv.rank].cells[0], x + 11, y + 16);
	}
}

// This should place a card in the buffer at position (x,y) top corner, using rank/suit from card_view and fb is buffer.
void set_card_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], card_view cv, int x, int y) {
	set_card_border_in_buffer(fb, x, y);
	set_card_view_in_buffer(fb, cv, x, y);
}


int main(int argc, char **argv) {

	//hide_cursor();

	// Determine terminal shape, and create 2d array frame buffer
	terminal_dimension window_size;
	terminal_dimension *term_dim = &window_size;

	// loads terminal dimensions to term_dim struct pointer
	set_terminal_size(term_dim);
	if (term_dim->columns == 0 || term_dim->rows == 0) {
		return -1;
	}

	// Create array to mimic current size. Set to empty (with null termination)
	cell frame_buffer[term_dim->rows][term_dim->columns];
	initialize_frame_buffer(frame_buffer, term_dim->rows, term_dim->columns);


	set_card_in_buffer(frame_buffer, (card_view){ Common_Ace,  Common_Spades}, 1, 327);
	set_card_in_buffer(frame_buffer, (card_view){ Common_Two, Common_Diamonds }, 1, 5);
	set_card_in_buffer(frame_buffer, (card_view){ Common_King, Common_Clubs }, 1, 10);
	set_card_in_buffer(frame_buffer, (card_view){ Common_Two, Common_Spades }, 1, 15);

	set_card_border_in_buffer(frame_buffer, 20, 20);
	set_card_view_in_buffer(frame_buffer, (card_view){ Common_Two, Common_Spades }, 20, 20);

	set_card_border_in_buffer(frame_buffer, 20, 200);
	set_card_view_in_buffer(frame_buffer, (card_view){ Common_Ten, Common_Hearts }, 20, 200);
/*
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
*/
	print_frame_buffer(frame_buffer, TERMINAL_MAX_ROWS, TERMINAL_MAX_COLUMNS);

	//show_cursor();

	return 0;
}


void show_cursor() {
	write(STDOUT_FILENO, "\033[?25h", sizeof("\033[?25h") - 1);
}

void hide_cursor() {
	write(STDOUT_FILENO, "\033[?25l", sizeof("\033[?25l") - 1);
}

void set_terminal_size(terminal_dimension *wd) {
	
	// determine how many cells in terminal program
	struct winsize w;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
		wd->rows = w.ws_row;
		wd->columns = w.ws_col;
	} else {
		wd->rows = 0;
		wd->columns = 0;
	}
	
}

void print_frame_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], int rows, int cols) {

	static char output[TERMINAL_MAX_ROWS * TERMINAL_MAX_COLUMNS * sizeof(cell) + TERMINAL_MAX_ROWS + OUTPUT_EXTRA_BYTES] = {0};
	memset(output, 0, sizeof(output));

	int index = 0;
	output[index++] = '\033';	// Move cursor to top
	output[index++] = '[';
	output[index++] = 'H';
	output[index++] = '\033';	// Clear screen from cursor down
	output[index++] = '[';
	output[index++] = 'J';
	
	int i, j, r;
	for (i = 0; i < rows; i++){
		for (j = 0; j < cols; j++) {
			r = 0;
			while (fb[i][j].ch[r] != '\0') {
				output[index++] = fb[i][j].ch[r++];
			}
		}
		output[index++] = '\n';
	}
	
	output[index++] = '\0';
	write(STDOUT_FILENO, output, index);
}

void initialize_frame_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], int rows, int cols) {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			fb[r][c].ch[0] = ' ';
			fb[r][c].ch[1] = '\0';
			fb[r][c].ch[2] = '\0';
			fb[r][c].ch[3] = '\0';
		}
	}
}

void set_component_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], cell component, int row, int col) {
	if (row < TERMINAL_MAX_ROWS && col < TERMINAL_MAX_COLUMNS) {
		fb[row][col].ch[0] = component.ch[0];
		fb[row][col].ch[1] = component.ch[1];
		fb[row][col].ch[2] = component.ch[2];
		fb[row][col].ch[3] = component.ch[3];
	}
}

void clear_frame_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], int rows, int cols) {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			fb[r][c].ch[0] = ' ';
			fb[r][c].ch[1] = '\0';
			fb[r][c].ch[2] = '\0';
			fb[r][c].ch[3] = '\0';
		}
	}
}
#include "../inc/public_terminal_ui.h"
#include "../inc/private_terminal_ui.h"


static void show_cursor() {
	write(STDOUT_FILENO, "\033[?25h", sizeof("\033[?25h") - 1);
}

static void hide_cursor() {
	write(STDOUT_FILENO, "\033[?25l", sizeof("\033[?25l") - 1);
}

static void set_component_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], cell component, int row, int col) {
	if (row < TERMINAL_MAX_ROWS && col < TERMINAL_MAX_COLUMNS) {
		fb[row][col].ch[0] = component.ch[0];
		fb[row][col].ch[1] = component.ch[1];
		fb[row][col].ch[2] = component.ch[2];
		fb[row][col].ch[3] = component.ch[3];
	}
}

static void set_card_border_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], int x, int y) {
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

static void set_card_view_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], card_view cv, int x, int y) {

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

// Returns 0 if successful
int set_terminal_size(terminal_dimension *wd) {

	// determine how many cells in terminal program
	struct winsize w;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
		wd->rows = w.ws_row;
		wd->columns = w.ws_col;
	} else {
		wd->rows = 0;
		wd->columns = 0;
	}
	
    if (wd->rows == 0 || wd->columns == 0) {
        return -1;
    }

    return 0;
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

// This should place a card in the buffer at position (x,y) top corner, using rank/suit from card_view and fb is buffer.
void set_card_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], card_view cv, int x, int y) {
	set_card_border_in_buffer(fb, x, y);
	set_card_view_in_buffer(fb, cv, x, y);
}
#include "common_card.h"
#include "internal_card.h"

/* Private API for rendering cards */
static void initialize_renderable_card(renderable_card *ctr) {
	set_border(ctr);
	set_rank(ctr);
	set_suit(ctr);
	set_blank(ctr);
}

static void set_border(renderable_card *ctr) {
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

static void set_rank(renderable_card *ctr) {
	memset(ctr->top_rank_row, 0, sizeof(ctr->top_rank_row));
	memset(ctr->bottom_rank_row, 0, sizeof(ctr->bottom_rank_row));

	// Top rank
	strncat(ctr->top_rank_row, left_vertical, UTF8_BYTE_SIZE);
	int trl = strlen(rank_symbols[ctr->card_data->rank]);
	strncat(ctr->top_rank_row, rank_symbols[ctr->card_data->rank], trl);
	memset(ctr->top_rank_row + UTF8_BYTE_SIZE + trl, ' ', 17 - trl);
	strncat(ctr->top_rank_row, right_vertical, UTF8_BYTE_SIZE);
	ctr->top_rank_row[23] = '\0';

	// Bottom rank
	strncat(ctr->bottom_rank_row, left_vertical, UTF8_BYTE_SIZE);
	memset(ctr->bottom_rank_row + UTF8_BYTE_SIZE, ' ', 17 - trl);
	strncat(ctr->bottom_rank_row, rank_symbols[ctr->card_data->rank], trl);
	strncat(ctr->bottom_rank_row, right_vertical, UTF8_BYTE_SIZE);
	ctr->bottom_rank_row[23] = '\0';
}

static void set_suit(renderable_card *ctr) {
	memset(ctr->top_suit_row, 0, sizeof(ctr->top_suit_row));
	memset(ctr->middle_suit_row, 0, sizeof(ctr->middle_suit_row));
	memset(ctr->bottom_suit_row, 0, sizeof(ctr->bottom_suit_row));
	
	// Top suit
	strncat(ctr->top_suit_row, left_vertical, UTF8_BYTE_SIZE);
	int tsl = strlen(suit_symbols[ctr->card_data->suit]);
	strncat(ctr->top_suit_row + UTF8_BYTE_SIZE, suit_symbols[ctr->card_data->suit], tsl);
	memset(ctr->top_suit_row + UTF8_BYTE_SIZE + tsl, ' ', 19 - tsl);
	strncat(ctr->top_suit_row, right_vertical, UTF8_BYTE_SIZE);
	ctr->top_suit_row[25] = '\0';

	// This sets middle suit TODO: mimic how cards actually show in the middle
	strncat(ctr->middle_suit_row, left_vertical, UTF8_BYTE_SIZE);
	memset(ctr->middle_suit_row + UTF8_BYTE_SIZE, ' ', 8);
	strncat(ctr->middle_suit_row + UTF8_BYTE_SIZE + 8, suit_symbols[ctr->card_data->suit], tsl);
	memset(ctr->middle_suit_row + UTF8_BYTE_SIZE + tsl + 8, ' ', 8);
	strncat(ctr->middle_suit_row + UTF8_BYTE_SIZE + tsl, right_vertical, UTF8_BYTE_SIZE);
	ctr->middle_suit_row[25] = '\0';
	// TODO: mimic how cards actually show in the middle (pattern)


	// Bottom suit
	strncat(ctr->bottom_suit_row, left_vertical, UTF8_BYTE_SIZE);
	memset(ctr->bottom_suit_row + UTF8_BYTE_SIZE, ' ', 19 - tsl);
	strncat(ctr->bottom_suit_row + UTF8_BYTE_SIZE + tsl, suit_symbols[ctr->card_data->suit], tsl);
	strncat(ctr->bottom_suit_row, right_vertical, UTF8_BYTE_SIZE);	
	ctr->bottom_suit_row[25] = '\0';
}

static void set_blank(renderable_card *ctr) {
	memset(ctr->blank_row, 0, sizeof(ctr->blank_row));

	strncat(ctr->blank_row, left_vertical, UTF8_BYTE_SIZE);
	memset(ctr->blank_row + UTF8_BYTE_SIZE, ' ', 17);
	strncat(ctr->blank_row, right_vertical, UTF8_BYTE_SIZE);
	ctr->blank_row[23] = '\0';
}

static void render_card(renderable_card *ctr) {
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
/* Private API for rendering cards */

/* Public API for rendering cards */
void render_selected_card(card_view *cv) {

    renderable_card display_card = {0};
	renderable_card *ctr = &display_card;

	memset(ctr, 0, sizeof(renderable_card));
	
    ctr->card_data = cv;

	initialize_renderable_card(ctr);

	render_card(ctr);
}
/* Public API for rendering cards */
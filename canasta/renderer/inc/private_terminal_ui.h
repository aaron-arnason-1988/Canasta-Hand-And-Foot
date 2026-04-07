#ifndef PRIVATE_TERMINAL_UI_H
#define PRIVATE_TERMINAL_UI_H

#define CARD_HEIGHT	13
#define CARD_WIDTH	19

#define OUTPUT_EXTRA_BYTES 10

typedef struct {
	cell cells[2];
} card_rank;

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

static void show_cursor();                                     // Private for now
static void hide_cursor();                                     // Private for now
static void set_component_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], cell component, int row, int col);           // Private
static void set_card_border_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], int x, int y);                             // Private
static void set_card_view_in_buffer(cell fb[TERMINAL_MAX_ROWS][TERMINAL_MAX_COLUMNS], card_view cv, int x, int y);                 // Private

#endif
#define SUIT_COUNT 5
#define RANK_COUNT 14
#define UTF8_BYTE_SIZE 3

static const char *trbl_corner =       "▚";
static const char *tlbr_corner =       "▞";
static const char *bottom_horizontal = "▄";
static const char *top_horizontal =    "▀";
static const char *left_vertical =     "▌";
static const char *right_vertical =    "▐";

static const char *suit_symbols[] = {"✪", "♥", "♦", "♣", "♠"};
static const char *rank_symbols[] = {"JR", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

typedef card_view card_view;

typedef struct card_to_render {
	char top_border_row[58];
	char top_rank_row[24];
	char top_suit_row[26];
	char blank_row[24];
	char middle_suit_row[26];
	char bottom_suit_row[26];
	char bottom_rank_row[24];
	char bottom_border_row[58];

	card_view *card_data;
} renderable_card;

static void initialize_renderable_card(renderable_card *ctr);
static void set_border(renderable_card *ctr);
static void set_rank(renderable_card *ctr);
static void set_suit(renderable_card *ctr);
static void set_blank(renderable_card *ctr);
static void render_card(renderable_card *ctr);
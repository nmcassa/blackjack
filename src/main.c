#include "cards.h"

int main(void) {
	srand(time(NULL));

	struct card* deck;
	deck = malloc(sizeof(struct card) * 52);

	build_deck(deck);
	build_deck_values(deck);
	shuffle_deck(deck);
	print_deck(deck);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
	char suit;
	char type;
	int value;
};

void build_deck(struct card* deck);
void build_deck_values(struct card* deck);

void shuffle_deck(struct card* deck);

void print_deck(struct card* deck);

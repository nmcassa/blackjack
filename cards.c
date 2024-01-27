#include "cards.h"

void build_deck(struct card* deck) {
	int num_suit = 4;
	int num_item = 13;

	char* suits = (char *) malloc(sizeof(char) * num_suit);

	suits[0] = 'H';
	suits[1] = 'D';
	suits[2] = 'C';
	suits[3] = 'S';

	char* items = (char *) malloc(sizeof(char) * 4);

	items[0] = 'A';
	items[1] = 'K';
	items[2] = 'Q';
	items[3] = 'J';

	int idx;
	for (int i = 0; i < num_suit; i++) {
		for (int j = 0; j < num_item; j++) {
			idx = i * num_item + j;
			deck[idx].suit = suits[i];
			if (j < num_suit) {
				deck[idx].type = items[j];
			} else {
				deck[idx].type = (j - 3) + '0';
			}
		}
	}
}

void build_deck_values(struct card* deck) {
	for (int i = 0; i < 52; i++) {
		if (deck[i].type == 'A') {
			deck[i].value = 11;
		} else if (deck[i].type == 'Q' || deck[i].type == 'K' ||
				deck[i].type == 'J' || deck[i].type == '1') {
			deck[i].value = 10;
		} else {
			deck[i].value = deck[i].type - '0';
		}
	}
}

void shuffle_deck(struct card* deck) {
	int a;
	int b;
	struct card temp;

	for (int i = 0; i < 1000; i++) {
		a = rand() % 52;
		b = rand() % 52;

		temp = deck[a];
		deck[a] = deck[b];
		deck[b] = temp;
	}
}

void print_deck(struct card* deck) {
	for (int i = 0; i < 52; i++) {
		printf("%c%c = %d\n", deck[i].suit, deck[i].type, deck[i].value);
	}
}

/*****************************************************************************
Name: randomtestcard1.c
Author: Bradford Witt
Date: November 22, 2019
Description: Random Test for baronRefactor()
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dominion.h"
#include "dominion.c"
#include "interface.h"
#include "rngs.h"
#include <time.h>

int main() {

	// Create variables
	srand(time(NULL));
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	struct gameState state;
	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];
	int p;
	int i;
	int check;
	int currentPlayer = 0;
	int nextPlayer = 1;
	int continueTesting = 1;
	int tmp;
	int t1 = 0;
	int t2 = 0;
	int t3 = 0;
	int t4 = 0;
	int t5 = 0;
	int r;

	printf("Start Test: baronRefactor()\n");

	while (continueTesting == 1) {
		memset(&state, 23, sizeof(struct gameState));
		r = initializeGame(2, k, 2, &state);
		state.handCount[0] = 4;
		state.hand[0][0] = baron;
		state.hand[0][1] = baron;
		state.hand[0][2] = baron;
		state.hand[0][3] = baron;
		memcpy(state.hand[p], coppers, sizeof(int) * state.handCount[0]);

		tmp = rand() % 5;

		if (tmp != 4) {
			state.hand[0][tmp] = estate;
		}

		baronRefactor(&state, 1, currentPlayer);

		if (tmp == 0) {
			assert(state.numBuys > 0);
			assert(state.coins == 0);
		}
		else {
			assert(state.numBuys > 0);
			assert(state.coins != 0);

		switch (tmp) {
			case 0:
					t1 = 1;
					break;
			case 1:
					t2 = 1;
					break;
		}

		if (t1 == 1 && t2 == 1) {
			continueTesting = 0;
		}
		}
	}

	continueTesting = 1;
	t1 = 0;
	t2 = 0;
	t3 = 0;
	t4 = 0;
	t5 = 0;

	while (continueTesting == 1) {
		memset(&state, 23, sizeof(struct gameState));
		r = initializeGame(2, k, 2, &state);
		state.handCount[0] = 4;
		state.hand[0][0] = baron;
		state.hand[0][1] = baron;
		state.hand[0][2] = baron;
		state.hand[0][3] = baron;
		memcpy(state.hand[p], coppers, sizeof(int) * state.handCount[0]);

		tmp = rand()  %5;

		if (tmp != 4) {
			state.hand[0][tmp] = estate;
		}

		baronRefactor(&state, 1, currentPlayer);

		i = 0;
		p = 1;
		check = 1;

		while (check) {
			if(state.hand[currentPlayer][p] == estate) {
				assert(state.hand[currentPlayer][p] == estate);
				assert(state.coins >= 4);
				assert(state.discard[currentPlayer][0] == baron);
				p++;
			}
			else if (p > state.handCount[currentPlayer]) {
				check = 0;
			}
			else {
				p++;
			}
		}

		switch (tmp) {
			case 0:
					t1 = 1;
					break;
			case 1:
					t2 = 1;
					break;
			case 2:
					t3 = 1;
					break;
			case 3:
					t4 = 1;
					break;
			case 4:
					t5 = 1;
					break;
		}

		if (t1 == 1 && t2 == 1 && t3 == 1 && t4 == 1 && t5 == 1) {
			continueTesting = 0;
		}
	}

	printf("Test Complete.\n");

}
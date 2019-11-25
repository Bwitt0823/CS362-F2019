/*****************************************************************************
Name: unittest2.c
Author: Bradford Witt
Date: November 10, 2019
Description: Test for minionRefactor()
*****************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {

	// Create variables
	int handpos = 0;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int bonus = 0;
	int seed = 100;
	int numPlayers = 2;
	int player = 0;
	struct gameState state;
	struct gameState test;
	int count1 = 0;
	int count2 = 0;
	int kingdomCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	// Initialize Game
	initializeGame(numPlayers, kingdomCards, seed, &state);

	printf("\n---------- Testing minionRefactor() ----------\n");

	memcpy(&test, &state, sizeof(struct gameState));
	cardEffect(minion, choice1, choice2, choice3, &state, handpos, &bonus);
	player = whoseTurn(&test);

	// Test the number of new cards added
	if ((state->handCount(whoseTurn(&state)) - test->handCount(player)) == 4) {
		printf("Pass");
	}
	else {
		printf("Fail");
	}

	// Test the return value
	if (1 != cardEffect(minion, choice1, choice2, choice3, &state, handpos, &bonus)) {
		printf("Pass");
	}
	else {
		printf("Fail");
	}

	printf("\n---------- Test Complete ----------\n");

	return 0;
}
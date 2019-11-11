/*****************************************************************************
Name: unittest4.c
Author: Bradford Witt
Date: November 10, 2019
Description: Test for tributeRefactor()
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
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    // Initialize Game
    initializeGame(numPlayers, kingdomCards, seed, &state);

    printf("\n---------- Testing tributeRefactor() ----------\n");

    memcpy(&test, &state, sizeof(struct gameState));
    cardEffect(tribute, choice1, choice2, choice3, &state, handpos, &bonus);
    player = whoseTurn(&test);

    printf("\n---------- Test Complete ----------\n");

    return 0;
}
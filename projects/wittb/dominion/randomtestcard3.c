/*****************************************************************************
Name: randomtestcard3.c
Author: Bradford Witt
Date: November 22, 2019
Description: Random Test for tributeRefactor()
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

    srand(time(NULL));
    int k[10] = { tribute, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    struct gameState state;
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    int currentPlayer = 0;
    int nextPlayer = 1;
    int continueTesting = 1;
    int tmp;
    int t1 = 0;
    int t2 = 0;
    int t3 = 0;
    int t4 = 0;
    int t5 = 0;
    int tributes = 0;
    int numVic = 0;
    int numTreas=0;
    int check;
    int i;
    int tributeRevealedCards[2] = {-1, -1};

    printf("Start Test: tributeRefactor()\n");

    while(continueTesting == 1)
    {

        tributes = 0;
        numVic = 0;
        numTreas = 0;

        int handPos = 0;
        memset(&state, 23, sizeof(struct gameState));
        int r = initializeGame(2, k, 2, &state);
        state.handCount[0] = 4;
        state.hand[0][0] = tribute;
        state.hand[0][1] = baron;
        state.hand[0][2] = mine;
        state.hand[0][3] = gardens;
        state.deckCount[1] = 3;

        tmp = rand() % 3;

        switch(tmp) {
            case 0:
                state.deck[1][0] = tribute;
                tributes++;
                break;
            case 1:
                state.deck[1][0] = gardens;
                numVic++;
                break;
            case 2:
                state.deck[1][0] = copper;
                numTreas++;
                break;
        }

        tmp = rand() % 3;

        switch(tmp) {
            case 0:
                state.deck[1][1] = tribute;
                tributes++;
                break;
            case 1:
                state.deck[1][1] = gardens;
                numVic++;
                break;
            case 2:
                state.deck[1][1] = copper;
                numTreas++;
                break;
        }

        tmp = rand() % 3;

        switch(tmp) {
            case 0:
                state.deck[1][2] = tribute;
                tributes++;
                break;
            case 1:
                state.deck[1][2] = gardens;
                numVic++;
                break;
            case 2:
                state.deck[1][2] = copper;
                numTreas++;
                break;
        }

            check = playTribute(&state, currentPlayer, nextPlayer, &tributeRevealedCards);

        if(tributes > 0) {
            t1 = 1;
            assert(state.numActions > 0);
        }

        if(numVic > 0) {
            t2 = 1;
            assert(state.handCount[0] > 4);
        }

        if(numTreas > 0) {
            t3 = 1;
            assert(state.coins > 0);
        }

        if(t1 == 1 && t2 == 1 && t3 == 1) {
            continueTesting=0;
        }

    }

    continueTesting = 1;
    t1 = 0;
    t2 = 0;
    t3 = 0;
    t4 = 0;
    t5 = 0;

    while(continueTesting == 1) {

        tributes = 0;
        numVi = 0;
        numTreas = 0;

        int handPos = 0;

        memset(&state, 23, sizeof(struct gameState));
        int r = initializeGame(2, k, 2, &state);
        state.handCount[0] = 4;
        state.hand[0][0] = tribute;
        state.hand[0][1] = baron;
        state.hand[0][2] = mine;
        state.hand[0][3] = gardens;

        tmp = rand() % 2;
        state.discardCount[1] = tmp;
        for(i = 0; i < tmp; i++) {
            state.discard[1][i] = baron;
        }


        tmp = rand() % 2;
        state.deckCount[1] = tmp;
        for(i = 0; i < tmp; i++) {
            state.deck[1][i] = baron;
        }

        if(state.discardCount[1] == 0 && state.deckCount[1] == 0) {
            check = playTribute(&state, currentPlayer, nextPlayer, &tributeRevealedCards);
            assert(state.discardCount[1] == 0);
            assert(state.deckCount[1] == 0);
            t1 = 1;
        }
        else if(state.discardCount[1] == 0 && state.deckCount[1] == 1) {
            check = playTribute(&state, currentPlayer, nextPlayer, &tributeRevealedCards);
            assert(state.deckCount[1] == 0);
            t2 = 1;
        }
        else if(state.discardCount[1] == 1 && state.deckCount[1] == 0) {
            check = playTribute(&state, currentPlayer, nextPlayer, &tributeRevealedCards);
            assert(state.discardCount[1] == 0);
            t3 = 1;
        }
        else {
            t4=1;
        }


        if(t1 == 1 && t2 == 1 && t3 == 1 && t4 == 1) {
            continueTesting=0;
        }

    }

    printf("Test Complete.\n");

}
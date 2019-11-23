/*****************************************************************************
Name: randomtestcard2.c
Author: Bradford Witt
Date: November 22, 2019
Description: Random Test for minioRefactor()
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

int main()
{

srand(time(NULL));
int k[10] = { adventurer, minion, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
struct gameState state;
int coppers[MAX_HAND];
int silvers[MAX_HAND];
int golds[MAX_HAND];
int p;
int i;
int currentPlayer = 0;
int nextPlayer = 1;
int continueTesting = 1
int tmp;
int t1 = 0;
int t2 = 0;
int t3 = 0;
int t4 = 0;
int t5 = 0;


printf("Start Test: minionRefactor()\n");


	while(continueTesting == 1) {
		tmp = rand()%3;


		memset(&state, 23, sizeof(struct gameState));
		int r = initializeGame(2, k, 2, &state);
		state.handCount[0] = 4;
		state.hand[0][0] = minion;
		state.hand[0][1] = baron;
		state.hand[0][2] = baron;
		state.hand[0][3] = baron;

		memcpy(state.hand[p], coppers, sizeof(int) * state.handCount[0]);

		if(tmp==1) {
			playMinion(&state, 0, 0, 0, currentPlayer);
			assert(state.numActions > 0);
			assert(state.hand[0][0] != minion);
			assert(state.coins >= 2);

			t1 = 1;

		}
		else if (tmp == 2) {

			tmpTwo = rand() % 8;

			for(i=0;i<tmpTwo; i++) {
				state.hand[1][i] = minion;
			}

			playMinion(1, tmp, 0, 0, &state, 0, 0);

			if(tmpTwo<4) {
				assert(state.numActions > 0);
				assert(state.hand[0][0] != minion);
				assert(state.coins == 0);
				assert(state.handCount[1] == 2);
				t2 = 1;
			}
			else if (tmpTwo>4) {
				assert(state.numActions > 0);
				assert(state.hand[0][0] != minion);
				assert(state.coins == 0);
				assert(state.handCount[1] == 4);
				t3 = 1;
			}
			else {
				assert(state.numActions > 0);
				assert(state.hand[0][0] != minion);
				assert(state.coins == 0);
				assert(state.handCount[1] == 4);
				t4 = 1;
			}
		}
		else {
			t5 = 1;
		}

		if(t1 == 1 && t2 == 1 && t3 == 1 && t4 == 1 && t5 == 1)
		{
			continueTesting = 0;
		}

	}

	printf("Test Complete.\n");

}
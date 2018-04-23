/* WhoseTurn test */

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int assertTrue(int test);

int main (int argc, char** argv) {
	int pass = 0;
	int expectedPlayer;
	int currentPlayer;
	int numPlayer = 2;
	int seed = 1000;
    struct gameState G;
    int i;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    printf ("TESTING WhoseTurn():\n");

    initializeGame(numPlayer, k, seed, &G);

    for (i = 0; i < numPlayer; i++)
    {
	   	//Begin turn
	   	currentPlayer = whoseTurn(&G);
	    expectedPlayer = i;
	    pass += assertTrue(expectedPlayer == currentPlayer);
	    printf("Player %d beginning turn\n", currentPlayer);

	    //Play card
	    G.hand[currentPlayer][0] = smithy;
	    playCard(0, 0, 0, 0, &G);
	    currentPlayer = whoseTurn(&G);
	    pass += assertTrue(expectedPlayer == currentPlayer);
	    printf("Player %d played card\n", currentPlayer);

	    //Buy card
	    G.hand[currentPlayer][1] = gold;
	    buyCard(silver, &G);
	    currentPlayer = whoseTurn(&G);
	    pass += assertTrue(expectedPlayer == currentPlayer);
	    printf("Player %d bought card\n", currentPlayer);

	    //End turn
	    endTurn(&G);
    }

    //Begin player 1 again
    expectedPlayer = 0;
    currentPlayer = whoseTurn(&G);
    pass += assertTrue(expectedPlayer == currentPlayer);
	printf("Player %d beginning turn again\n", currentPlayer);

    if (pass == 0){
		printf("All tests passed!\n");
    }
}

int assertTrue(int test)
{
	if (test)
	{
		printf("PASS: ");
		return 0;
	}
	
	printf("FAIL: ");
	return 1;
}
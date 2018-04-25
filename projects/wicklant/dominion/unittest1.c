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

    printf ("--------TESTING WhoseTurn Function--------\n");

    initializeGame(numPlayer, k, seed, &G);

    for (i = 0; i < numPlayer; i++)
    {
	   	//Begin turn
	   	currentPlayer = whoseTurn(&G);
	    expectedPlayer = i;
	    printf("\tPlayer %d begins turn: ", i + 1);
	    pass += assertTrue(expectedPlayer == currentPlayer);
	    printf("\t\tPlayer Expected = %d Actual = %d\n", expectedPlayer +1, currentPlayer +1);

	    //Play card
	    G.hand[currentPlayer][0] = smithy;
	    playCard(0, 0, 0, 0, &G);
	    currentPlayer = whoseTurn(&G);
	    printf("\tPlayer %d played card: ", i + 1);
	    pass += assertTrue(expectedPlayer == currentPlayer);
	    printf("\t\tPlayer Expected = %d Actual = %d\n", expectedPlayer +1, currentPlayer +1);
	    

	    //Buy card
	    G.hand[currentPlayer][1] = gold;
	    buyCard(silver, &G);
	    currentPlayer = whoseTurn(&G);
	    printf("\tPlayer %d bought card: ", i + 1);
	    pass += assertTrue(expectedPlayer == currentPlayer);
	    printf("\t\tPlayer Expected = %d Actual = %d\n", expectedPlayer +1, currentPlayer +1);

	    //End turn
	    endTurn(&G);
    }

    //Begin player 1 again
    expectedPlayer = 0;
    currentPlayer = whoseTurn(&G);
    printf("\tPlayer %d beginning turn again: ", (i % 2) + 1);
    pass += assertTrue(expectedPlayer == currentPlayer);
	printf("\t\tExpected = %d Actual = %d\n", expectedPlayer +1, currentPlayer+1);

	if (pass == 0)
    	printf("All tests successfully passed!\n\n");
    else
    	printf("\n");

    return 0;
}

int assertTrue(int test)
{
	if (test)
	{
		printf("PASS\n");
		return 0;
	}
	
	printf("FAIL\n");
	return 1;
}
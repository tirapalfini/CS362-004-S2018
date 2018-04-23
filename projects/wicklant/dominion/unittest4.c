/* numHandCards test */

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int assertTrue(int test);

int main (int argc, char** argv) {
	int pass = 0;
	int expectedHand;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int numPlayers = 2;
	int seed = 1000;
	struct gameState G;
	int player;

    initializeGame(numPlayers, k, seed, &G);

	printf("Testing numHandCards\n");

	//empty hand - boundary case
	expectedHand = 0;
	for (player = 0; player < G.numPlayers; player++)
	{
		G.handCount[player] = 0;
		int currentHandCards = numHandCards(&G);
		assertTrue(expectedHand == currentHandCards);
		printf("Player %d has %d cards\n", player, currentHandCards);
		endTurn(&G);
	}

	//current count 5 cards - regular gameplay
	expectedHand = 5;
	for (player = 0; player < G.numPlayers; player++)
	{
		int currentHandCards = numHandCards(&G);
		assertTrue(expectedHand == currentHandCards);
		printf("Player %d has %d cards\n", player, currentHandCards);
		endTurn(&G);
	}

	//max count 500 cards -boundary case
	expectedHand = MAX_HAND;
	for (player = 0; player < G.numPlayers; player++)
	{
		G.handCount[player] = MAX_HAND;
		int currentHandCards = numHandCards(&G);
		assertTrue(expectedHand == currentHandCards);
		printf("Player %d has %d cards\n", player, currentHandCards);
		endTurn(&G);
	}

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
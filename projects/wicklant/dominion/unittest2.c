/* fullDeckCount test */

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>


int assertTrue(int test);
int fillCards(int player, struct gameState *state);


int main (int argc, char** argv) {
	int pass = 0;
	int numPlayer = 1;
	int seed = 1000;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    struct gameState G;
    initializeGame(numPlayer, k, seed, &G);

    printf("Testing fullDeckCount()\n");

    G.deckCount[0] = 0;
    G.handCount[0] = 0;
    G.discardCount[0] = 0;
    fillCards(0, &G);
    pass += assertTrue(0 == fullDeckCount(0, 0, &G));
    printf("Empty deck -- expected 0, deck fullcount %d\n", fullDeckCount(0, 0, &G));	

    G.deckCount[0] = 5;
    fillCards(0, &G);
    pass += assertTrue(5 == fullDeckCount(0, 0, &G));
    printf("Deck with 5 cards -- expected count 5, fulldeck count %d\n", fullDeckCount(0, 0, &G));	

    G.deckCount[0] = 0;
    G.handCount[0] = 5;
    fillCards(0, &G);
    pass += assertTrue(5 == fullDeckCount(0, 0, &G));
    printf("Hand with 5 cards -- expected count 5, fulldeck count %d\n", fullDeckCount(0, 0, &G));	

    G.handCount[0] = 0;
    G.discardCount[0] = 5;
    fillCards(0, &G);
    pass += assertTrue(5 == fullDeckCount(0, 0, &G));
    printf("Discard with 5 cards -- expected count 5, fulldeck count %d\n", fullDeckCount(0, 0, &G));	

    G.deckCount[0] = 5;
    G.handCount[0] = 5;
    fillCards(0, &G);
    pass += assertTrue(15 == fullDeckCount(0, 0, &G));
    printf("All decks with 5 cards -- expected count 15, fulldeck count %d\n", fullDeckCount(0, 0, &G));	

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

/* Fill in cards */
int fillCards(int player, struct gameState *state){
	int i;

	for (i = 0; i < state->deckCount[player]; i++)
	{
		state->deck[player][i] = 0;
	}

	for (i = 0; i < state->handCount[player]; i++)
	{
		state->deck[player][i] = 0;
	}

	for (i = 0; i < state->discardCount[player]; i++)
	{
		state->discard[player][i] = 0;
	}

	return 0;
}
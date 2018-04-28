#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <string.h>
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
    struct gameState test1;
    struct gameState test2;
    struct gameState test3;
    struct gameState test4;
    struct gameState test5;
    int actualCount;

    initializeGame(numPlayer, k, seed, &G);

    printf("--------TESTING fullDeckCount Function --------\n");

    //Test if fullDeckCount works for boundary case (empty deck)
    G.deckCount[0] = 0;
    G.handCount[0] = 0;
    G.discardCount[0] = 0;
    fillCards(0, &G);
    actualCount = fullDeckCount(0, 0, &G);
    printf("\tEmpty deck: ");
    pass += assertTrue(0 == actualCount);
    printf("\t\tExpected = 0 Actual = %d\n", actualCount);	

    //Test if fullDeckCount counts deck cards
    memcpy(&test1, &G, sizeof(struct gameState));
    test1.deckCount[0] = 5;
    fillCards(0, &test1);
    actualCount = fullDeckCount(0, 0, &test1);
    printf("\tDeck with 5 cards: ");
    pass += assertTrue(5 == actualCount);
    printf("\t\tExpected = 5 Actual = %d\n", actualCount);	

    //Test if fullDeckCount counts hand cards
    memcpy(&test2, &G, sizeof(struct gameState));
    test2.handCount[0] = 5;
    fillCards(0, &test2);
    actualCount = fullDeckCount(0, 0, &test2);
    printf("\tHand with 5 cards: ");
    pass += assertTrue(5 == actualCount);
    printf("\t\tExpected = 5 Actual = %d\n", actualCount);	

    //Test if fullDeckCount counts discard cards
    memcpy(&test3, &G, sizeof(struct gameState));
    test3.discardCount[0] = 5;
    fillCards(0, &test3);
    actualCount = fullDeckCount(0, 0, &test3);
    printf("\tDiscard with 5 cards: ");
    pass += assertTrue(5 == actualCount);
    printf("\t\tExpected = 5 Actual = %d\n", actualCount);	

    //Test if fullDeckCount adds all cards correctly
    memcpy(&test4, &G, sizeof(struct gameState));
    test4.deckCount[0] = 5;
    test4.handCount[0] = 5;
    test4.discardCount[0] = 5;
    fillCards(0, &test4);
    actualCount = fullDeckCount(0, 0, &test4);
    printf("\tAll three decks with 5 cards: ");
    pass += assertTrue(15 == actualCount);
    printf("\t\tExpected = 15 Actual = %d\n", actualCount);

    //Test if fullDeckCount correctly adds boundary case (max decks)
    memcpy(&test5, &G, sizeof(struct gameState));
    test5.deckCount[0] = MAX_DECK;
    test5.handCount[0] = MAX_HAND;
    test5.discardCount[0] = MAX_DECK;
    fillCards(0, &test5);
    int expectedCount =  MAX_DECK + MAX_HAND + MAX_DECK;
    actualCount = fullDeckCount(0, 0, &test5);
    printf("\tAll three decks with max cards: ");
    pass += assertTrue(expectedCount == actualCount);
    printf("\t\tExpected = %d Actual = %d\n", expectedCount, actualCount);	

    if (pass == 0)
        printf("All tests successfully passed!\n\n");
    else
        printf("Some tests failed\n\n");

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
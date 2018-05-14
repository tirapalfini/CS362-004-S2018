#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int assertTrue(int test);

int main (int argc, char** argv) {

	int tests = 1000;
	int i;
	int correctCards = 0;
	int smithyDiscarded = 0;
	int cardPlayed = 0;
	int successesCards = 0;
	int successesPlay = 0;
	int succcessesDiscard = 0;
	srand(time(0));

	printf("--------TESTING playCardSmithy Function with RANDOM--------\n");
	
	for (i = 0; i < tests; i++)
	{
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				sea_hag, tribute, smithy, council_room};
		int numPlayers = 2;
		int seed = rand();
		struct gameState G;
		int choice1 = 0;
		int choice2 = 0;
		int choice3 = 0;
		int bonus = 0;

		initializeGame(numPlayers, k, seed, &G);

		//Rabdomize hand position for card
		int handPos = rand() % G.handCount[whoseTurn(&G)];

		//Expected hand after smithy card played  = prior hand + (3 new cards - 1 discarded smithy card) 
		int expectedHand = numHandCards(&G) + 2;

		//Expected played cards after smithy card discarded = prior played cards + 1 card
		int expectedPlayedCards = G.playedCardCount + 1;

		//Set card in hand position to smithy
		G.hand[whoseTurn(&G)][handPos] = smithy;
		
		//Test if Smithy card is played
		cardPlayed += assertTrue(cardEffect(smithy, choice1, choice2, choice3, &G, handPos, &bonus) == 0);
		
		//Test if smithy card adds correct number of cards to hand
		correctCards += assertTrue(expectedHand == numHandCards(&G));

		int discarded = G.playedCardCount;
		smithyDiscarded += assertTrue(expectedPlayedCards == discarded);

		if (cardPlayed == 0)
	    	successesPlay++;
	    if (correctCards == 0)
	    	successesCards++;
	    if (smithyDiscarded == 0)
		    succcessesDiscard++;

	}
	printf("Smithy card was played successfully: %d of %d times\n", successesPlay, tests);
	printf("3 cards were added to hand: %d of %d times\n", successesCards, tests);
	printf("Smithy card was discarded: %d of %d times\n", succcessesDiscard, tests); 
    return 0;

}

int assertTrue(int test)
{
	if (test)
	{
		return 0;
	}
	
	return 1;
}
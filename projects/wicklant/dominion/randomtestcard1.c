#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int assertTrue(int test);
//int playCardVillage2(struct gameState *state, int currentPlayer, int handPos);

int main (int argc, char** argv) {
	int tests = 1000;
	int i;
	int cardAdded = 0;
	int actionsAdded = 0;
	int cardPlayed = 0;
	int successesCardAdded = 0;
	int successesPlay = 0;
	int succcessesActionsAdded = 0;
	srand(time(0));

	printf("--------TESTING playCardVillage Function with RANDOM--------\n");

	for (i = 0; i < tests; i++)
	{
		//int pass = 0;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				sea_hag, tribute, smithy, council_room};
		int numPlayers = 2;
		int seed = rand();
		struct gameState G;
		int choice1 = 0;
		int choice2 = 0;
		int choice3 = 0;
		int handPos = 0;
		int bonus = 0;

		initializeGame(numPlayers, k, seed, &G);

		//Expected hand after village card played = prior hand + (1 new card - village discarded)
		int expectedHand = numHandCards(&G) + 0;

		//Expected actions after village card played = prior hand + 2 cards
		int expectedActions = G.numActions + 2;

		//Test if card is played
		cardPlayed += assertTrue(cardEffect(village, choice1, choice2, choice3, &G, handPos, &bonus) == 0);

		//Test if 1 card is added to hand after village card played
		cardAdded += assertTrue(expectedHand == numHandCards(&G));


		//Test if 2 actions added after village card played
		actionsAdded += assertTrue(expectedActions = G.numActions);

		if (cardPlayed == 0)
	    	successesPlay++;
	    if (cardAdded == 0)
	    	successesCardAdded++;
	    if (actionsAdded == 0)
		    succcessesActionsAdded++;		
	}
	printf("Village card was played successfully: %d of %d times\n", successesPlay, tests);
	printf("1 card was added to hand: %d of %d times\n", successesCardAdded, tests);
	printf("2 actions were added:: %d of %d times\n", succcessesActionsAdded, tests); 
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
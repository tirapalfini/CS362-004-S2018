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
	int cardPlayed = 0;
	int successesCards = 0;
	int successesPlay = 0;
	srand(time(0));

	printf("--------TESTING playCardAdventurer Function with RANDOM--------\n");
	
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
		int handPos = 0;
		int bonus = 0;
		int player;

		initializeGame(numPlayers, k, seed, &G);
		//int c;
		player = whoseTurn(&G);

		//Expected hand after adventurer card played = prior hand + 2 cards
		int expectedHand = numHandCards(&G) + 2;

		//Test if card is played
		cardPlayed += assertTrue(cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, &bonus) == 0);

		//Test if 2 cards added after adventurer played
		correctCards += assertTrue(expectedHand == numHandCards(&G));

		//Test if the new cards added are treasure cards
		int lastCard = G.hand[player][G.handCount[player]-1];
		int otherCard = G.hand[player][G.handCount[player]-2];
		
		correctCards += assertTrue((lastCard == copper || lastCard == silver || lastCard == gold) && 
			(otherCard == copper || otherCard == silver || otherCard == gold));

	    if (cardPlayed == 0)
	    	successesPlay++;
	    if (correctCards == 0)
	    {
	    	successesCards++;
	    }
	}
	printf("Adventurer card was played successfully: %d of %d times\n", successesPlay, tests);
	printf("2 treasure cards were added to hand: %d of %d times\n", successesCards, tests); 
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

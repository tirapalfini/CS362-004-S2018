#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int assertTrue(int test);

int main (int argc, char** argv) {
	int pass = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int numPlayers = 2;
	int seed = 1000;
	struct gameState G;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int handPos = 0;
	int bonus = 0;
	int player;

	initializeGame(numPlayers, k, seed, &G);

	printf("--------TESTING playCardAdventurer Function--------\n");

	//Expected hand after adventurer card played = prior hand + 2 cards
	int expectedHand = numHandCards(&G) + 2;
	
	//Test if card is played
	printf("\tThe adventurer card was played: ");
	pass += assertTrue(cardEffect(adventurer, choice1, choice2, choice3, &G, handPos, &bonus) == 0);
	

	//Test if 2 cards added after adventurer played
	printf("\t2 cards were to the hand: ");
	pass += assertTrue(expectedHand == numHandCards(&G));
	printf("\t\tExpected = %d Actual = %d\n", expectedHand, numHandCards(&G));

	//Test if the new cards added are treasure cards
	player = whoseTurn(&G);
	int lastCard = G.hand[player][G.handCount[player]-1];
	int otherCard = G.hand[player][G.handCount[player]-2];
	
	printf("\tThe two new cards are treasure cards: ");
	pass += assertTrue((lastCard == copper || lastCard == silver || lastCard == gold) && 
		(otherCard == copper || otherCard == silver || otherCard == gold));
	printf("\t\tExpected = %d, %d, or %d\n", copper, silver, gold);
	printf("\t\tNewCard1 Actual = %d\n", lastCard);
	printf("\t\tNewCard2 Actual = %d\n", otherCard);

	if (pass == 0){
    	printf("All tests successfully passed!\n\n");
    }
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
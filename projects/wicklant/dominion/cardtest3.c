#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int assertTrue(int test);
//int playCardVillage2(struct gameState *state, int currentPlayer, int handPos);

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

	initializeGame(numPlayers, k, seed, &G);

	printf("--------TESTING playCardVillage Function--------\n");

	//Expected hand after village card played = prior hand + (1 new card - village discarded)
	int expectedHand = numHandCards(&G) + 0;

	//Expected actions after village card played = prior hand + 2 cards
	int expectedActions = G.numActions + 2;

	//Test if card is played
	printf("\tThe village card was played: ");
	pass += assertTrue(cardEffect(village, choice1, choice2, choice3, &G, handPos, &bonus) == 0);
	//pass += assertTrue(playCardVillage2(&G, whoseTurn(&G), handPos)== 0);
	
	//Test if 1 card is added to hand after village card played
	printf("\t1 card added to the hand: ");
	pass += assertTrue(expectedHand == numHandCards(&G));
	printf("\t\tExpected = %d Actual = %d\n", expectedHand, numHandCards(&G));
	

	//Test if 2 actions added after village card played
	printf("\tThe village card added 2 actions: ");
	pass += assertTrue(expectedActions = G.numActions);
	printf("\t\t Expected = %d Actual = %d\n", expectedActions, G.numActions);
	
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

//Village Kingdom card is played correctly
/*int playCardVillage2(struct gameState *state, int currentPlayer, int handPos){
  //+1 Card
  drawCard(currentPlayer, state);
  
  //+2 Actions
  state->numActions = state->numActions + 2;
  
  //discard played card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}*/
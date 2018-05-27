#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int assertTrue(int test);
//int playCardSmithy2(struct gameState *state, int currentPlayer, int handPos);

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

	printf("--------TESTING playCardSmithy Function--------\n");
	//Expected hand after smithy card played  = prior hand + (3 new cards - 1 discarded smithy card) 
	int expectedHand = numHandCards(&G) + 2;
	//Expected played cards after smithy card discarded = prior played cards + 1 card
	int expectedPlayedCards = G.playedCardCount + 1;

	//Set first card in hand to smithy
	G.hand[whoseTurn(&G)][0] = smithy;
	
	//printf("after %d\n", G.hand[whoseTurn(&G)][0]);
	
	//Test if Smithy card is played
	printf("\tThe smithy card was played: ");
	pass += assertTrue(cardEffect(smithy, choice1, choice2, choice3, &G, handPos, &bonus) == 0);
	//pass += assertTrue(playCardSmithy2(&G, whoseTurn(&G), handPos) == 0);
	
	printf("\t3 cards were added to the hand: ");
	pass += assertTrue(expectedHand == numHandCards(&G));
	printf("\t\tExpected = %d Actual = %d\n", expectedHand, numHandCards(&G));

	printf("\tSmithy card was discarded: ");
	int discarded = G.playedCardCount;
	pass += assertTrue((expectedPlayedCards == discarded) &&
		(G.playedCards[discarded-1] == smithy));
	printf("\t\tPlayedDeck Expected = %d Actual = %d\n\t\tDiscardedCard Expected = %d Actual = %d\n", 
		expectedPlayedCards, discarded, smithy, G.playedCards[discarded-1]);
	
	if (pass == 0){
    	printf("All tests successfully passed!\n\n");
    }
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

//Smithy Kingdom card is played correctly
/*int playCardSmithy2(struct gameState *state, int currentPlayer, int handPos){
  int i;
  //+3 Cards
  for (i = 0; i < 3; i++){
    drawCard(currentPlayer, state);
  }
  //discard card from hand
  discardCard(handPos, currentPlayer, state, 0);
  return 0;
}*/
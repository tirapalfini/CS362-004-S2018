/* Test Minion Card */
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>

int assertTrue(int test);

int main (int argc, char** argv) {
	int pass = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int numPlayers = 2;
	int seed = 1000;
	struct gameState G;
	struct gameState test1;
	struct gameState test2;
	struct gameState test3;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int handPos = 0;
	int bonus = 0;
	int oldHand[G.numPlayers][MAX_HAND];
	int i;
	int j;
	int handChanged = 0;
	int opponentHandsChanged = 0;
	int fourCardsNotDrawn = 0;

	initializeGame(numPlayers, k, seed, &G);

	printf("--------TESTING playCardMinion Function --------\n");
	printf("TESTING Choice 1:\n");

	//Test if 2 coins added to player's hand if choice1 is chosen
	memcpy(&test1, &G, sizeof(struct gameState));
	choice1 = 1;
	int expectedCoin = test1.coins + 2;

	printf("\tThe minion card was played with choice 1: ");
	pass += assertTrue(cardEffect(minion, choice1, choice2, choice3, &test1, handPos, &bonus) == 0);
	
	printf("\t2 coins were added for current player: ");
	pass += assertTrue(expectedCoin == test1.coins);
	printf("\t\tExpected = %d Actual = %d\n", expectedCoin, test1.coins);

	printf("TESTING Choice 2 with opponents' hand count < 5:\n");

	//Test if new cards have been drawn for player only with choice2 
	memcpy(&test2, &G, sizeof(struct gameState));
	choice1 = 0;
	choice2 = 1;

	// Make all opponents have empty hands
	for (i = 0; i < test2.numPlayers; i++)
	{
		if (i != whoseTurn(&test2))
		{
			test2.handCount[i] = 0;
		}
	}

	//Fill in oldHands for all players
	for (i = 0; i < test2.numPlayers; i++)
	{
		for (j = 0; j < test2.handCount[i]; j++)
			{
				oldHand[i][j] = test2.hand[i][j];
			}
	}
	
	printf("\tThe minion card was played with choice 2: ");
	pass += assertTrue(cardEffect(minion, choice1, choice2, choice3, &test2, handPos, &bonus) == 0);
	

	//Check if the currentPlayer's hand has changed
	for (i = 0; i < numHandCards(&test2); i++)
	{
		if(oldHand[whoseTurn(&test2)][i] != test2.hand[whoseTurn(&test2)][i])
			handChanged = 1;
	}

	//Check to see how many opponent's hands have been changed
	for (i = 0; i < test2.numPlayers; i++)
	{
		if (i != whoseTurn(&test2))
		{
			for (j = 0; j < test2.handCount[i]; j++)
			{
				if (oldHand[i][j] != test2.hand[i][j])
				{
					opponentHandsChanged++;
					continue;
				}

			}

		}
	}

	printf("\tHand was discarded for current player: ");
	pass += assertTrue(handChanged == 1);

	printf("\t4 new cards were drawn for current player: ");
	pass += assertTrue(numHandCards(&test2) == 4);
	printf("\t\t Expected = 4 Actual = %d\n", numHandCards(&test2));

	printf("\tOpponents hands not changed: ");
	pass += assertTrue(opponentHandsChanged == 0);


	printf("TESTING Choice 2 with opponents hand count 5\n");

	//Test choice2 with opponents having 5 cards in hand
	memcpy(&test3, &G, sizeof(struct gameState));
	handChanged = 0;
	opponentHandsChanged = 0;
	
	//Make each opponent have 5 cards in hand
	for (i = 0; i < test3.numPlayers; i++)
	{
		if(i != whoseTurn(&test3))
		{
			for (j = 0; j < 5; j++)
			{
				drawCard(i, &test3);
				oldHand[i][j] = test3.hand[i][j];
				//printf("player %d card %d = %d\n", i, j, oldHand[i][j]);
			}
		}
	}

	printf("\tThe minion card was played with choice 2: ");
	pass += assertTrue(cardEffect(minion, choice1, choice2, choice3, &test3, handPos, &bonus) == 0);
	
	//Check if the currentPlayer's hand has changed
	for (i = 0; i < numHandCards(&test3); i++)
	{
		if(oldHand[whoseTurn(&test3)][i] != test3.hand[whoseTurn(&test3)][i])
			handChanged = 1;
	}

	//Check to see how many opponents hands have been changed
	for (i = 0; i < test3.numPlayers; i++)
	{
		if (i != whoseTurn(&test3))
		{
			for (j = 0; j < 5; j++)
			{
				if (oldHand[i][j] != test3.hand[i][j])
				{
					opponentHandsChanged++;
					break;
				}

			}

		}
	}

	//Check to see if 4 cards drawn for each player
	for (i = 0; i < test3.numPlayers; i++)
	{
		if (test3.handCount[i] != 4)
			fourCardsNotDrawn = 1;
	}

	printf("\t\tThe old hand discarded for current player: ");
	pass += assertTrue(handChanged == 1);

	printf("\t\t4 new cards drawn for current player: ");
	pass += assertTrue(numHandCards(&test2) == 4);

	printf("\t\tOpponents hands have all changed: ");
	pass += assertTrue(opponentHandsChanged == (test3.numPlayers -1));

	printf("\t\tEach opponent has drawn 4 cards: ");
	pass += assertTrue(fourCardsNotDrawn == 0);

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
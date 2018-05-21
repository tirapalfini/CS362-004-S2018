#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int assertTrue(int test);

int main (int argc, char** argv) {
	int pass = 0;

    printf("--------TESTING kingdomCards Function --------\n");

	int expected[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    int* cardsArray = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy);

    int i;
    printf("\tTest positions of cards:\n");
    for (i = 0; i < 10; i++)
    {
    	printf("\t\tPosition %d: Expected = %d Actual = %d:\t ", i, expected[i], cardsArray[i]);
        pass += assertTrue(expected[i] == cardsArray[i]);

    }

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



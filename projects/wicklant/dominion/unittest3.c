/* kingdomCards */

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int assertTrue(int test);

int main (int argc, char** argv) {
	int pass = 0;

	int expected[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    int* cardsArray = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy);

    int i;

    for (i = 0; i < 10; i++)
    {
    	pass += assertTrue(expected[i] == cardsArray[i]);
    	printf("position %d\n", i);

    }

    if (pass == 0)
    {
    	printf("All test successfully passed\n");
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



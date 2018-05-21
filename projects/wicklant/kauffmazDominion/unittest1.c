#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <string.h>
#include <stdlib.h>

int assertTrue(int test);
void isOver(int number);

int main (int argc, char** argv) {

  int pass = 0;
  int numPlayer = 2;
  int seed = 1000;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
  struct gameState G;
  struct gameState test1;
  struct gameState test2;
  struct gameState test3;
  struct gameState test4;
  int actual;
  int i;

  initializeGame(numPlayer, k, seed, &G);

  printf("--------TESTING isGameOver Function --------\n");
  
  //Testing empty province stack
  memcpy(&test1, &G, sizeof(struct gameState));
  printf("\tProvince cards is empty: ");
  test1.supplyCount[province] = 0;
  actual = isGameOver(&test1);
  pass += assertTrue(1 == actual);
  printf("\t\tExpected: "); 
  isOver(1); 
  printf(" Actual: ");
  isOver(actual);
  printf("\n");

  //Testing non-empty province stack
  memcpy(&test2, &G, sizeof(struct gameState));
  printf("\tProvince cards is not empty: ");
  test2.supplyCount[province] = 1;
  actual = isGameOver(&test2);
  pass += assertTrue(0 == actual);
  printf("\t\tExpected: "); 
  isOver(0); 
  printf(" Actual: ");
  isOver(actual);
  printf("\n");

  //Testing with 3 empty supply piles
  memcpy(&test3, &G, sizeof(struct gameState));
  printf("\t3 supply piles are empty: ");
  for(i = 0; i < 3; i++)
  {
    test3.supplyCount[i] = 0;
  }
  actual = isGameOver(&test3);
  pass += assertTrue(1 == actual);
  printf("\t\tExpected: "); 
  isOver(1); 
  printf(" Actual: ");
  isOver(actual);
  printf("\n");

  //Testing with no empty supply piles
  memcpy(&test4, &G, sizeof(struct gameState));  
  printf("\tNo supply piles are empty: ");
  for(i = 0; i < 25; i++)
  {
    test4.supplyCount[i] = 1;
  }
  actual = isGameOver(&test4);
  pass += assertTrue(0 == actual);
  printf("\t\tExpected: "); 
  isOver(0); 
  printf(" Actual: ");
  isOver(actual);
  printf("\n");

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

void isOver(int number)
{
  if(number == 1)
  {
    printf("game is over");
  }
  else
    printf("game continues");
}
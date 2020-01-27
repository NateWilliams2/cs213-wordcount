//Lab: Warmup by Coles "Emi" Bergman-Corbet and Nathaniel Williams
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

// Here are some handy C preprocessor definitions for suits of cards
// Source: http://stackoverflow.com/questions/27133508/how-to-print-spades-hearts-diamonds-etc-in-c-and-linux
#if defined(_WIN32) || defined(__MSDOS__)
   #define SPADE   "\x06"
   #define CLUB    "\x05"
   #define HEART   "\x03"
   #define DIAMOND "\x04"
#else
   #define SPADE   "\xE2\x99\xA0"
   #define CLUB    "\xE2\x99\xA3"
   #define HEART   "\xE2\x99\xA5"
   #define DIAMOND "\xE2\x99\xA6"
#endif

void intToCard(int a)
{
  assert((a > -1)&&(a < 52));
  //cards arranged first by suit, then inside suit by number. Eg. 0-12 is all hearts
  int cardNum = a%13;
  int suit = (a/13);

  //print card number
  if(cardNum > 0 && cardNum < 10)
    printf("%d", cardNum + 1);
  switch (cardNum) {
  case 0:
    printf("A");
    break;
  case 10:
    printf("J");
    break;
  case 11:
    printf("Q");
    break;
  case 12:
    printf("K");
    break;
  }

  //print suit value
  switch(suit){
  case 0:
    printf("%s\n", HEART);
    break;
  case 1:
    printf("%s\n", DIAMOND);
    break;
  case 2:
    printf("%s\n", CLUB);
    break;
  case 3:
    printf("%s\n", SPADE);
    break;
  }

}

void shuffle(int* deck){
  //seed the rand generator
  srand(time(NULL));

  //initialize deck
  int index = 0;
  for(int i =0; i < 52; i++) {
      deck[i] = i;
    }
  //randomly swap to shuffle deck
  for(int i = 51; i > 0; i--) {
      index = rand()%i;
      int tmp = deck[i];
      deck[i] = deck[index];
      deck[index] = tmp;
  }
}

int main(int argc, char** argv) {
  int deck[52]; //scope deck for shuffling
  shuffle(deck);
  for(int i = 0; i < 52;i++)
    {
      intToCard(deck[i]);
    }
  return 0;
}

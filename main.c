#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

int main (int argc, char * argv[]) {

  if ( argc < 2 ) {
    printf("Program expects a text file input. Exiting...\n");
    exit(1);
  }
  offer * c = readOffers(argv[1]);

  offer * temp = c;
  while ( temp != NULL ) {
    printOffer(temp);
    temp = temp->next;
  }
  printf("\n");
  printTable(p);
  printf("\n");
  createSchedule();
  printSchedule();
}

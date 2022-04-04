#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"
#include "bitmaps.c"
#include "read-offers.c"
#include "print-utils.c"
#include "scheduler.c"


int main (int argc, char * argv[]) {

  if ( argc < 2 ) {
    printf("Program expects a text file input. Exiting...\n");
    exit(1);
  }
  offer * c = readOffers(argv[1]);

  offer * temp = c;
  while ( temp != NULL ) {
    if(p[gradeIndex(temp->grade)][temp->times - 1] == NULL) {
      p[gradeIndex(temp->grade)][temp->times - 1] = createBitmap(temp->times, temp->id);
    } else {
      p[gradeIndex(temp->grade)][temp->times - 1] = insertHead(createBitmap(temp->times, temp->id), p[gradeIndex(temp->grade)][temp->times - 1]);
    }

    printOffer(temp);
    temp = temp->next;
  }
  printf("\n");
  printTable(p);
  printf("\n");
  createSchedule();
  printSchedule();
}

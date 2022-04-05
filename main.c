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
    int i = gradeIndex(temp->grade);
    int j = temp->times - 1;
    bitmap * m = createBitmap(temp->times, temp->id);

    if(p[i][j] == NULL) {
      p[i][j] = m;
    } else {
      p[i][j] = insertHead(m, p[i][j]);
    }

    printOffer(temp);
    temp = temp->next;
  }
  printf("\n");
  printTable(p);
  printf("\n");
  createSchedule();
  // REMOVE THIS PRINT
  printf("PRINTING SCHEDULE\n");
  printSchedule();
}

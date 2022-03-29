#include <stdio.h>
#include "scheduler.h"

void printOffer (offer * k) {
    if (k == NULL)
        return;

    printf("Offer id: %2d ", k->id);

    printf("Grade: %12s ", k->grade);
    person * t = k->teacher;

    printf("Teacher(s): ");
    while (t != NULL) {
        printf("%10s ", t->name);
        t = t->next;
    }

    t = k->assistant;
    printf("Assistant(s): ");
    while (t != NULL) {
        printf("%10s ", t->name);
        t = t->next;
    }
    printf("\n");
}

void printBinary (char n) {
  if (n == 0) {
    printf("0\n");
    return;
  }
  unsigned int s = 0x0080;
  int i;
  for (i=0; i<8; i++) {
    if (n & s) printf("1");
    else printf("0");
    s = s >> 1;
  }
  printf("\n");
}

void printBitmap (bitmap * m) {

  if ( m == NULL) return;

  printf("Bitmap/Offer id: %2d\n", m->offer_id);
  int i;
  printf("\tBitarrays:\n");
  for ( i=0; i<D; i++ ) {
    printf("\t%d: ", i);
    printBinary(m->b[i]);
  }
}

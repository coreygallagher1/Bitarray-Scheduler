#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scheduler.h"

// TODO
bit_array createBitArray (int times, int position) {
  // implement the function and replace the return line below
  return 0;
}

// TODO
bitmap * createBitmap (int times, int id) {
  // implement the function and replace the return line below
  return NULL;
}

int main () {

  bitmap * m = createBitmap(1, 0);
  printBitmap(m);
  m = createBitmap(2, 1);
  printBitmap(m);
  m = createBitmap(3, 2);
  printBitmap(m);
  m = createBitmap(4, 3);
  printBitmap(m);
  m = createBitmap(5, 4);
  printBitmap(m);

  free(m);
}

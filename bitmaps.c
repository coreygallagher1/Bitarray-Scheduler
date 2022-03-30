//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "scheduler.h"
#include "print-utils.c"

// TODO
bit_array createBitArray (int times, int position) {
  char a[5] = {1, 3, 7, 15, 31};
  bit_array bitArr;
  
  if(times + position > 5){
    bitArr = 0;
  }

  else{
    bitArr = a[times-1] << position;
  }

  return bitArr;

  return 0;
}

// TODO
bitmap * createBitmap (int times, int id) {
  bitmap bitMap;
  bitmap * b = (bitmap *) malloc(sizeof(bitmap));
  bitMap.offer_id = id;
  
    for(int i = 0; i < 5; i++){
      bitMap.b[i] = createBitArray(times, i);
    }
    *b = bitMap;
    return b;
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

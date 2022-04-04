//#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "scheduler.h"
//#include "print-utils.c"

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


/* TODO: insert n in the beginning of list head */
bitmap * insertHead (bitmap * head, bitmap * n) {
  if(head == NULL) {
    return n;
  } 
  if(n == NULL) {
    return head;
  }

  n->next = head;
  head = n;

  return head;
}


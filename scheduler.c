#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

#define MASK 0x1F  // assuming D == 5, then it covers all D days

// TODO
option * optionsForGrade (bitmap * g[D]) {
  option *new_option = malloc(sizeof(option));

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      if(*g[j]->b == 31) {
        new_option->offer_id[0] = g[j]->offer_id;
        new_option->a[0] = *g[j]->b;
      }
      if(i != j){
        int x = *g[i]->b;
        int y = *g[j]->b;
        if(x + y == 31) {
          
        }
      }
    }
  }
  // implement this function and change the following return statement
  return NULL;
}

void createSchedule () {
  int i;
  for (i=0; i<G; i++) {
    schedule[i] = optionsForGrade(p[i]);
  }
}

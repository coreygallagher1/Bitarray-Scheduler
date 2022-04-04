#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

#define MASK 0x1F  // assuming D == 5, then it covers all D days

// TODO
option * optionsForGrade (bitmap * g[D]) {
  // implement this function and change the following return statement
  return NULL;
}

void createSchedule () {
  int i;
  for (i=0; i<G; i++) {
    schedule[i] = optionsForGrade(p[i]);
  }
}

#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

#define MASK 0x1F  // assuming D == 5, then it covers all D days

// TODO
option * optionsForGrade (bitmap * g[D]) {
  option *new_option = malloc(sizeof(option));
//test
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      /*if(*g[j]->b == MASK) {
        printf("5 Days a week\n");
      }*/
      /*if(g[j]->b[0] == NULL || g[j]->b[1] == NULL) {
        printf("Exiting\n");
        exit(1);
      }*/
      if(g[i] == NULL) {
        printf("NULL\n");
      } else {
        printf("NOT NULL\n");
        if(((g[i]->b[0])^(g[i]->b[0])) == MASK) {
            printf("Match found\n");
        }
      }
      /*if((*g[i]->b[0]) == NULL || (*g[j]->b[0])) {
        printf("Exiting\n");
        exit(1);
      }*/

      /*if( ((*g[i]->b) ^ (*g[j]->b)) == MASK) {
          printf("Match found\n");
      }*/

      /*if(((g[j]->b[0])^(g[i]->b[0])) == MASK) {
        printf("Compatable teachers\n");
        //new_option->offer_id[0] = g[j]->offer_id;
        //new_option->a[0] = *g[j]->b;
      }
      if(((g[j]->b[1])^(g[i]->b[1])) == MASK) {
        printf("Compatable teachers\n");
        //new_option->offer_id[0] = g[j]->offer_id;
        //new_option->a[0] = *g[j]->b;
      }*/

      /*if(i != j){
        int x = *g[i]->b;
        int y = *g[j]->b;
        if(x + y == 31) {

        }
      }*/
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

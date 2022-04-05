#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

#define MASK 0x1F  // assuming D == 5, then it covers all D days

// TODO
option * optionsForGradeOLD (bitmap * g[D]) {
  option *new_option = malloc(sizeof(option));

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      /*if(*g[j]->b == MASK) {
        printf("5 Days a week\n");
      }*/
      /*if(g[j]->b[0] == NULL || g[j]->b[1] == NULL) {
        printf("Exiting\n");
        exit(1);
      }*/
      if(i != j) {
        if(g[i] == NULL && g[j]==NULL) {
          printf("NULL\n");
        } else {
          printf("NOT NULL %d, %d\n", i,j);
          printBitmap(g[i]);
          printBitmap(g[j]);
          printf("Test1: %d\n", ((g[0]->b[0])^(g[0]->b[1])));
          //printf("Test2: %d\n", ((g[i]->b[1])^(g[j]->b[1])));
          if(((g[i]->b[0])^(g[i]->b[0])) == MASK) {
              printf("Match found\n");
          }
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

/*option * insertOptionHead (option * head, option * n) {
  if(head != NULL) {
    n->next = head;
    head = n;
  } else {
    return n;
  }

  return head;
}*/

option * optionsForGrade (bitmap * g[D]) {
  option *head = malloc(sizeof(option));

  //Teachers who teach all 5 days
  if(g[4] != NULL) {
    head->offer_id[0] = g[4]->offer_id;
    head->offer_id[1] = INVALID_OFFER_ID;
    head->a[0] = g[4]->b[0];
    head->a[1] = INVALID_BIT_ARRAY;
  }

  //Matching Days 1 & 4
  if(g[0] != NULL && g[3] != NULL) {
    option *new_option1 = malloc(sizeof(option));
    option *new_option2 = malloc(sizeof(option));

    new_option1->offer_id[0] = g[0]->offer_id;
    new_option1->offer_id[1] = g[3]->offer_id;
    new_option1->a[0] = g[0]->b[0];
    new_option1->a[1] = g[3]->b[1];

    if(head == NULL) {
      head = new_option1;
    } else {
      new_option1->next = head;
      head = new_option1;
    }

    new_option2->offer_id[0] = g[0]->offer_id;
    new_option2->offer_id[1] = g[3]->offer_id;
    new_option2->a[0] = g[0]->b[4];
    new_option2->a[1] = g[3]->b[0];

    new_option2->next = head;
    head = new_option2;

    if(g[1] == NULL || g[2] == NULL) head->next->next = NULL;
  }

  //Matching Days 2 & 3
  if(g[1] != NULL && g[2] != NULL) {
    option *new_option1 = malloc(sizeof(option));
    option *new_option2 = malloc(sizeof(option));

    new_option1->offer_id[0] = g[1]->offer_id;
    new_option1->offer_id[1] = g[2]->offer_id;
    new_option1->a[0] = g[1]->b[0];
    new_option1->a[1] = g[2]->b[2];

    if(head == NULL) {
      head = new_option1;
    } else {
      new_option1->next = head;
      head = new_option1;
    }

    new_option2->offer_id[0] = g[1]->offer_id;
    new_option2->offer_id[1] = g[2]->offer_id;
    new_option2->a[0] = g[1]->b[3];
    new_option2->a[1] = g[2]->b[0];

    new_option2->next = head;
    head = new_option2;

    head->next->next = NULL;
  }

  if(head->a[0] == NULL) {
    return NULL;
  }

  return head;
}

void createSchedule () {
  int i;
  for (i=0; i<G; i++) {
    schedule[i] = optionsForGrade(p[i]);
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scheduler.h"
//#include "bitmaps.c"

int gradeIndex(char * s) {

  if ( s == NULL ) return -1;

  if ( strstr(" PreK\0", s) != NULL )
    return 0;
  if ( strstr(" K-1st\0", s) != NULL )
    return 1;
  if ( strstr(" 2nd\0", s) != NULL )
    return 2;
  if ( strstr(" 3rd-4th\0", s) != NULL )
    return 3;
  if ( strstr(" 5th-6th\0", s) != NULL )
    return 4;
  if ( strstr(" Junior High\0", s) != NULL )
    return 5;
  if ( strstr(" High School\0", s) != NULL )
    return 6;

  return -2;
}

offer * readOfferLine (char * line, int id) {
    char *token1, *token2;

    offer *new_offer = malloc(sizeof(offer));
    person *person_head = malloc(sizeof(person));

    new_offer->id = id;

    token1 = strtok(line, ":");

    token2 = strtok(NULL, ",");
    strcpy(new_offer->grade, token2);
    //printf("1: %s\n", token2);
    
    token2 = strtok(NULL, " ,\n");
    
    new_offer->times = strtol(token2, NULL, 10);

    token2 = strtok(NULL, " ,\n");
    //printf("3: %s\n", token2);

    if(token2 != NULL) {
        person *assistant = malloc(sizeof(person));

        strcpy(assistant->name, token2);
        new_offer->assistant = assistant;
        //printf("Assistant: %s\n", token2);
    }
    
    strcpy(person_head->name, token1);

    new_offer->teacher = person_head;

    return new_offer;
}

// TODO
offer * readOffers (char * filename) {
  char line[1024];
  FILE *file = fopen(filename, "r");

  offer *offer_head = malloc(sizeof(offer));
  int offer_id = 0;

  if(file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  while(fgets(line, 1024, file)) {
    if(offer_id > 0) {
        offer *new_offer = malloc(sizeof(offer));

        new_offer = readOfferLine(line, offer_id);
        new_offer->next = offer_head;
        offer_head = new_offer;
    } else {
        offer_head = readOfferLine(line, offer_id);
    }
    
    offer_id++;
  }

  return offer_head;
}

// int main () {

//   offer * c = readOffers("teacher-offers.txt");
//   // sample file, your tests could include different ones

//   offer * temp = c;
//   while ( temp != NULL ) {
//     //p[gradeIndex(temp->grade)][temp->times - 1] = createBitmap(temp->times, temp->id);

//     //printOffer(temp);
//     temp = temp->next;
//   }
//     p[0][0] = createBitmap(1,1);
//     p[0][1] = createBitmap(2,2);
//     printTable(p);
// }

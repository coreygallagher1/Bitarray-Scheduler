#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 50 // maximum number of characters in a name

// Do NOT modify
typedef struct person_struct {
    char name[L];
    struct person_struct * next;
} person;

// Do NOT modify
typedef struct teaching_offer {
    int id; // unique identifier for offer
    int times; // times per week of instruction
    char grade[L]; // grade level
    person * teacher; // one or more lead teachers
    person * assistant; // one or more assistants
    struct teaching_offer * next;
} offer;

// Do NOT modify
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

char * trimLeadingSpaces(char * s) {
    char *token = strtok(s, " ");

    return token;
}

offer * readOfferLine (char * line, int id) {
    char *token1, *token2, *token3;

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

int main () {

  offer * c = readOffers("teacher-offers.txt");
  // sample file, your tests could include different ones

  offer * temp = c;
  while ( temp != NULL ) {
    printOffer(temp);
    temp = temp->next;
  }
}

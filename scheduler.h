#include <stdio.h>
#include <stdlib.h>

#define L 50 // maximum number of characters in a name
#define D 5 // number of days of instruction in the schedule

typedef struct person_struct {
    char name[L];
    struct person_struct * next;
} person;

typedef struct teaching_offer {
    int id; // unique identifier for offer
    int times;
    char grade[L];
    person * teacher; // one or more lead teachers
    person * assistant; // one or more assistants
    struct teaching_offer * next;
} offer;

typedef unsigned char bit_array; // D should be less than 8

typedef struct bitmap_struct {
    int offer_id;
    bit_array b[D];
    struct bitmap_struct * next;
} bitmap;

void printOffer (offer * k);
void printBinary (char n);
void printBitmap (bitmap * m);

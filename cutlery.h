//
// Created by Denisa on 12/20/2019.
//

#ifndef FOOD_ORDERING_CUTLERY_H
#define FOOD_ORDERING_CUTLERY_H
#define MAX_CUTLERY_NAME 30

typedef struct _cutlery {
    char ** cutleryAnswer;
} cutlery;

cutlery createCutlery();
void displayCutleryOptions(int cutleryValue, cutlery c);
void freeCutlery(cutlery * c);
#endif //FOOD_ORDERING_CUTLERY_H

//
// Created by Denisa on 11/28/2019.
//

#ifndef FOOD_ORDERING_LOADDATA_H
#define FOOD_ORDERING_LOADDATA_H

#endif //FOOD_ORDERING_LOADDATA_H

#define MAX_DRINK_NAME 30
#define MAX_SPECIFIC_FOOD_NAME 30


int countSpecificFoods(int * noOfSpecificFoods, char * line, int index);
char * constructSpecificProductX(char *delimiter, int index);
void constructCharPrice(char *delimiter, int index, char *charPrice);
void cutName(int index, char ** foodTypes);
void delimitingLineFood(char * line, char ** foodTypes, int index, char *** specificFoods, double ** prices, char * charPrice);
int getNumberOf(char * charNumber, char * line, FILE *data);
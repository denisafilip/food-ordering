//
// Created by Denisa on 11/28/2019.
//

#ifndef FOOD_ORDERING_LOADDATA_H
#define FOOD_ORDERING_LOADDATA_H

#endif //FOOD_ORDERING_LOADDATA_H

#define MAX_DRINK_NAME 30
#define MAX_SPECIFIC_FOOD_NAME 30
#define MAX_LINE 255

int countSpecificFoods(int * noOfSpecificFoods, char line[], int index);
void substractSpecificFood (const char *delimiter, char *** specificFoods, int indexColumn, int indexRow, int index);
void substractCharPrice(const char *delimiter, int index, char charPrice[]);
void substractSpecificDrink(const char *delimiter, char ** drinks, int indexRow, int index);
void cutName(int index, char ** foodTypes);
void delimitingLineFood(char * line, char ** foodTypes, int index, char *** specificFoods, double ** prices, char * charPrice);
void delimitingLineDrinks(char * line, char ** drinks, char * charPrice, double * pricesDrinks);
int getNumberOf(char * charNumber, char * line, FILE *data);
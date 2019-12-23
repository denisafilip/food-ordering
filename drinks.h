//
// Created by Denisa on 12/22/2019.
//

#ifndef FOOD_ORDERING_DRINKS_H
#define FOOD_ORDERING_DRINKS_H

typedef struct _drinks {
    char * name;
    double price;
} drinks;

void displayDrinksOptions(int noOfDrinks, char * foodTypes, drinks * d);
void delimitingLineDrinks(char * line, char * charPrice, drinks * d);
void freeDrinkMemory(int noOfDrinks, drinks * d);
#endif //FOOD_ORDERING_DRINKS_H

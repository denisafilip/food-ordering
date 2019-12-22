//
// Created by Denisa on 11/28/2019.
//
#include <stdlib.h>
#include "extraAssignment3.h"

void freeFoodMemory(int noOfFoodTypes, char ** foodTypes, int * noOfSpecificFoods, char *** specificFoods, double ** prices, user u) {
    for (int i=0; i<noOfFoodTypes; i++) {
        for (int j=0; j<noOfSpecificFoods[i]; j++) {
            free(specificFoods[i][j]);
        }
        free(specificFoods[i]);
        free(prices[i]);
        free(foodTypes[i]);
    }
    free(specificFoods);
    free(prices);
    free(foodTypes);
    free(noOfSpecificFoods);
    freeUserData(&u);
}

void freeDrinkMemory(int noOfDrinks, char ** drinks, double * pricesDrinks) {
    for (int i=0; i<noOfDrinks; i++) {
        free(drinks[i]);
    }
    free(drinks);
    free(pricesDrinks);
}
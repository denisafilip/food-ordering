//
// Created by Denisa on 11/4/2019.
#include <stdio.h>
#include "display.h"

void displayFoodOptions(int noOfFoodTypes, char ** foodTypes) {
    printf("Please choose the food you feel like eating today: \n");
    for (int i=0; i<noOfFoodTypes; i++) {
        putchar('a' + i);
        printf(") %s \n", foodTypes[i]);
    }
    printf("%c) Go Back \n", 'a' + noOfFoodTypes);
}

void displaySpecificFoodOptions(int noOfSpecificFoods, char * foodTypes, char ** specificFoods, double * prices) {
    printf("Please choose the type of %s\n", foodTypes);

    for (int i=0; i<noOfSpecificFoods; i++) {
        putchar('a' + i);
        printf(") %s: %.2lf \n", specificFoods[i], prices[i]);
    }
    printf("%c) Go Back \n", 'a' + noOfSpecificFoods);
}

void getAdditionalInfo(char additionalInfo[], int *state) {
    printf("Any additional info? \n");
    gets(additionalInfo);
    (*state)++;
}
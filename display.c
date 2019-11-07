//
// Created by Denisa on 11/4/2019.

#include <stdio.h>

#define MAX_FOOD_TYPE_NAME 30
#define MAX_SPECIFIC_FOOD_NAME 20
#define MAX_DRINK_NAME 30
#define MAX_CUTLERY_NAME 30

void displayFoodOptions(int noOfFoodTypes, char foodTypes[][MAX_FOOD_TYPE_NAME]) {
    printf("Please choose the food you feel like eating today: \n");
    for (int i=0; i<noOfFoodTypes; i++) {
        putchar('a' + i);
        printf(") %s \n", foodTypes[i]);
    }
    printf("%c) Go Back \n", 'a' + noOfFoodTypes);
}

void displaySpecificFoodOptions(int noOfDishes, char foodTypes[], char food[][MAX_SPECIFIC_FOOD_NAME], int prices[]) {
    printf("Please choose the type of %s \n", foodTypes);
    for (int i=0; i<noOfDishes; i++) {
        putchar('a' + i);
        printf(") %s: %d \n", food[i], prices[i]);
    }
    printf("%c) Go Back \n", 'a' + noOfDishes);
}

void displayDrinksOptions(int noOfDrinks, char foodTypes[], char drinks[][MAX_DRINK_NAME], int drinksPrices[]) {
    printf("Please choose a drink to go with your %s \n", foodTypes);
    for (int i=0; i<noOfDrinks-1; i++) {
        putchar('a' + i);
        printf(") %s: %d \n", drinks[i], drinksPrices[i]);
    }
    printf("%c) %s \n", 'a' + noOfDrinks - 1, drinks[4]);
    printf("%c) Go Back \n", 'a' + noOfDrinks);
}

void displayCutleryOptions(int cutlery, char cutleryAnswer[][MAX_CUTLERY_NAME]) {
    printf("Do you want cutlery? \n");
    for (int i=0; i < cutlery; i++) {
        putchar('a' + i);
        printf(") %s \n", cutleryAnswer[i]);
    }
    printf("%c) Go Back \n", 'a' + cutlery);
}

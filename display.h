//
// Created by Denisa on 11/4/2019.
//

#ifndef FOOD_ORDERING_DISPLAY_H
#define FOOD_ORDERING_DISPLAY_H

#endif //FOOD_ORDERING_DISPLAY_H
#define MAX_FOOD_TYPE_NAME 30
#define MAX_SPECIFIC_FOOD_NAME 20
#define MAX_DRINK_NAME 30
#define MAX_CUTLERY_NAME 30

void displayFoodOptions (int noOfFoodTypes, char foodTypes[][MAX_FOOD_TYPE_NAME]);
void displaySpecificFoodOptions(int noOfDishes, char foodTypes[], char food[][MAX_SPECIFIC_FOOD_NAME], int prices[]);
void displayDrinksOptions(int noOfDrinks, char foodTypes[], char drinks[][MAX_DRINK_NAME], int drinksPrices[]);
void displayCutleryOptions(int cutlery, char cutleryAnswer[][MAX_CUTLERY_NAME]);
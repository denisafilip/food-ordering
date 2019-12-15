//
// Created by Denisa on 11/4/2019.
//

#ifndef FOOD_ORDERING_DISPLAY_H
#define FOOD_ORDERING_DISPLAY_H

#endif //FOOD_ORDERING_DISPLAY_H

#define MAX_CUTLERY_NAME 30
#define MAX_ADDITIONAL_INFO 50

void displayFoodOptions (int noOfFoodTypes, char ** foodTypes);
void displaySpecificFoodOptions(int noOfSpecificFoods, char * foodTypes, char ** specificFoods, double * prices);
void displayDrinksOptions(int noOfDrinks, char * foodTypes, char ** drinks, double * pricesDrinks);
void displayCutleryOptions(int cutlery, char cutleryAnswer[][MAX_CUTLERY_NAME]);
void getAdditionalInfo(char additionalInfo[], int *state);
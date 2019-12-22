//
// Created by Denisa on 11/4/2019.
//

#ifndef FOOD_ORDERING_DISPLAY_H
#define FOOD_ORDERING_DISPLAY_H

#endif //FOOD_ORDERING_DISPLAY_H


#define MAX_ADDITIONAL_INFO 50

void displayFoodOptions (int noOfFoodTypes, char ** foodTypes);
void displaySpecificFoodOptions(int noOfSpecificFoods, char * foodTypes, char ** specificFoods, double * prices);
void getAdditionalInfo(char additionalInfo[], int *state);
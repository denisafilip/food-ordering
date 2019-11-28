#include <stdio.h>
#include <stdlib.h>
#include "loadData.h"
#include "display.h"
#include "choice.h"
#include "accountData.h"
#include "freeMemory.h"

#define LOAD_DATA "Please load the data:"

int main() {
    FILE *data = fopen("data.txt", "r");
    if(data == NULL){
        printf(LOAD_DATA "\n");
        data = stdin;
    }
    char username[20], password[20];
    int noOfFoodTypes, foodTypeChoice, specificFoodChoice, drinkChoice, noOfDrinks;
    int cutlery = 2, cutleryChoice;
    int state = 0;
    int orderConfirmed = 0;
    char cutleryAnswer[][MAX_CUTLERY_NAME] = {"Yes!", "No, thanks!"}, additionalInfo[MAX_ADDITIONAL_INFO];
    char line[MAX_LINE];
    char charPrice[MAX_LINE];
    char *charNumber;
    //foods
    noOfFoodTypes = getNumberOf(charNumber, line, data);
    int * noOfSpecificFoods = (int*)malloc(noOfFoodTypes * sizeof(int));
    char ** foodTypes = (char**)malloc(noOfFoodTypes * sizeof(char*));
    char *** specificFoods = (char***)malloc(noOfFoodTypes * sizeof(char**));
    double ** prices = (double**)malloc(noOfFoodTypes * sizeof(double*));
    for (int i=0; i<noOfFoodTypes; i++) {
        fgets(line, MAX_LINE, data);
        noOfSpecificFoods[i] = countSpecificFoods(noOfSpecificFoods, line, i);
        //putting data into foodTypes
        foodTypes[i] = (char*)malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
        //putting data into specificFoods and prices
        specificFoods[i] = (char**)malloc(noOfSpecificFoods[i] * sizeof(char*));
        prices[i] = (double*)malloc(noOfSpecificFoods[i] * sizeof(double));
        delimitingLineFood(line, foodTypes, i, specificFoods, prices, charPrice);
    }
    //drinks
    noOfDrinks = getNumberOf(charNumber, line, data);
    char ** drinks = (char**)malloc(noOfDrinks * sizeof(char*));
    double * pricesDrinks = (double*)malloc(noOfDrinks * sizeof(double));
    fgets(line, MAX_LINE, data);
    delimitingLineDrinks(line, drinks, charPrice, pricesDrinks);

    printf("Welcome to Food Thingies! \n");
    while (!orderConfirmed) {
        switch (state) {
            case 0: {
                inputAccountData(username, password);
                state++;
                break;
            }
            case 1: {
                displayFoodOptions(noOfFoodTypes, foodTypes);
                foodTypeChoice = getChoiceIndex(noOfFoodTypes, &state);
                break;
            }
            case 2: {
                displaySpecificFoodOptions(noOfSpecificFoods[foodTypeChoice], foodTypes[foodTypeChoice], specificFoods[foodTypeChoice], prices[foodTypeChoice]);
                specificFoodChoice = getChoiceIndex(noOfSpecificFoods[foodTypeChoice], &state);
                break;
            }
            case 3: {
                displayDrinksOptions(noOfDrinks, foodTypes[foodTypeChoice], drinks, pricesDrinks);
                drinkChoice = getChoiceIndex(noOfDrinks+1, &state);
                break;
            }
            case 4: {
                displayCutleryOptions(cutlery, cutleryAnswer);
                cutleryChoice = getChoiceIndex(cutlery, &state);
                break;
            }
            case 5: {
                getAdditionalInfo(additionalInfo, &state);
                break;
            }
            case 6: {
                displayAccountData(username);
                displayCustomerOrder(specificFoods[foodTypeChoice][specificFoodChoice], prices[foodTypeChoice][specificFoodChoice], drinks[drinkChoice], pricesDrinks[drinkChoice], cutleryAnswer[cutleryChoice], additionalInfo, drinkChoice);
                orderConfirmed = getFinalOrderChoiceIndex(&state, username);
                break;
            }
        }
    }
    freeFoodMemory(noOfFoodTypes, foodTypes, noOfSpecificFoods, specificFoods, prices);
    freeDrinkMemory(noOfDrinks, drinks, pricesDrinks);
    return 0;
}
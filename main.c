#include <stdio.h>
#include <stdlib.h>
#include "loadData.h"
#include "display.h"
#include "choice.h"
#include "accountData.h"
#include "freeMemory.h"
#include "extraAssignment3.h"
#include "encryption.h"

#define MAX_FOOD_TYPE_NAME 30

int main() {

    FILE *data = fopen("data.txt", "r");
    if(data == NULL){
        printf(LOAD_DATA "\n");
        data = stdin;
    }
    char username[MAX_USERNAME];
    int noOfFoodTypes, foodTypeChoice, specificFoodChoice, drinkChoice, noOfDrinks;
    int cutlery = 2, cutleryChoice;
    int state = 0;
    int orderConfirmed = 0;
    char cutleryAnswer[][MAX_CUTLERY_NAME] = {"Yes!", "No, thanks!"}, additionalInfo[MAX_ADDITIONAL_INFO];
    char * line = (char*)malloc(MAX_LINE * sizeof(char));
    char * charPrice = (char*)malloc(MAX_LINE * sizeof(char));
    char *charNumber = "";
    user u = createUser();
    enum state {
        LOGIN_PROCESS, CHOOSE_FOOD_TYPE, CHOOSE_SPECIFIC_FOOD, CHOOSE_DRINKS, CHOOSE_CUTLERY, INPUT_ADDITIONAL_INFO, CONFIRM_ORDER
    };
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
    //extra assignment 3
    while (!orderConfirmed) {
        switch (state) {
            case LOGIN_PROCESS: {
                loginProcess(u, &state);
                break;
            }
            case CHOOSE_FOOD_TYPE: {
                displayFoodOptions(noOfFoodTypes, foodTypes);
                foodTypeChoice = getChoiceIndex(noOfFoodTypes, &state);
                break;
            }
            case CHOOSE_SPECIFIC_FOOD: {
                displaySpecificFoodOptions(noOfSpecificFoods[foodTypeChoice], foodTypes[foodTypeChoice], specificFoods[foodTypeChoice], prices[foodTypeChoice]);
                specificFoodChoice = getChoiceIndex(noOfSpecificFoods[foodTypeChoice], &state);
                break;
            }
            case CHOOSE_DRINKS: {
                displayDrinksOptions(noOfDrinks, foodTypes[foodTypeChoice], drinks, pricesDrinks);
                drinkChoice = getChoiceIndex(noOfDrinks+1, &state);
                break;
            }
            case CHOOSE_CUTLERY: {
                displayCutleryOptions(cutlery, cutleryAnswer);
                cutleryChoice = getChoiceIndex(cutlery, &state);
                break;
            }
            case INPUT_ADDITIONAL_INFO: {
                getAdditionalInfo(additionalInfo, &state);
                break;
            }
            case CONFIRM_ORDER: {
                displayAccountData(username);
                displayCustomerOrder(specificFoods[foodTypeChoice][specificFoodChoice], prices[foodTypeChoice][specificFoodChoice], drinks[drinkChoice], pricesDrinks[drinkChoice], cutleryAnswer[cutleryChoice], additionalInfo, drinkChoice);
                orderConfirmed = getFinalOrderChoiceIndex(&state, u);
                break;
            }
        }
    }
    freeFoodMemory(noOfFoodTypes, foodTypes, noOfSpecificFoods, specificFoods, prices, u);
    freeDrinkMemory(noOfDrinks, drinks, pricesDrinks);
    fclose(data);
    return 0;
}
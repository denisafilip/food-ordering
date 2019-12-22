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
    int cutleryValue = 2, cutleryChoice;
    int state = 0;
    int orderConfirmed = 0;
    char additionalInfo[MAX_ADDITIONAL_INFO];
    char * line = (char*)malloc(MAX_LINE * sizeof(char));
    char * charPrice = (char*)malloc(MAX_LINE * sizeof(char));
    char *charNumber = "";
    user u = createUser();
    cutlery c = createCutlery();
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
    drinks * drink = (drinks*)malloc(noOfDrinks * sizeof(drinks));
    fgets(line, MAX_LINE, data);
    delimitingLineDrinks(line, charPrice, drink);

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
                displayDrinksOptions(noOfDrinks, foodTypes[foodTypeChoice], drink);
                drinkChoice = getChoiceIndex(noOfDrinks+1, &state);
                break;
            }
            case CHOOSE_CUTLERY: {
                displayCutleryOptions(cutleryValue, c);
                cutleryChoice = getChoiceIndex(cutleryValue, &state);
                break;
            }
            case INPUT_ADDITIONAL_INFO: {
                getAdditionalInfo(additionalInfo, &state);
                break;
            }
            case CONFIRM_ORDER: {
                displayAccountData(username);
                displayCustomerOrder(specificFoods[foodTypeChoice][specificFoodChoice], prices[foodTypeChoice][specificFoodChoice], &drink[drinkChoice], c, additionalInfo, drinkChoice);
                orderConfirmed = getFinalOrderChoiceIndex(&state, u);
                break;
            }
        }
    }
    freeFoodMemory(noOfFoodTypes, foodTypes, noOfSpecificFoods, specificFoods, prices, u);
    freeDrinkMemory(noOfDrinks, drink);
    freeCutlery(&c);
    fclose(data);
    return 0;
}
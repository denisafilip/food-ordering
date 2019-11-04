#include <stdio.h>
#include "display.h"
#include "choice.h"
#include "accountData.h"

#define MAX_FOOD_TYPE_NAME 30
#define MAX_SPECIFIC_FOOD_NAME 20
#define MAX_DRINK_NAME 30
#define MAX_CUTLERY_NAME 30

void getAdditionalInfo(char additionalInfo[], int *state);

int main() {
    printf("Welcome to Food Thingies! \n");
    char username[20], password[20];
    int noOfFoodTypes = 3, foodTypeChoice, specificFoodChoice, drinkChoice, noOfDrinks = 5, drinksPrices[] = {5, 5, 5, 4}, noOfDishes[] = {3, 2, 4}, cutlery = 2, cutleryChoice, state=0, orderConfirmed = 0;
    char foodTypes[][30] = {"Pizza", "Pasta", "Salad"};
    char food[3][4][MAX_SPECIFIC_FOOD_NAME] = {
            {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
            {"Chicken Alfredo", "Mac & Cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}
    };
    int prices[3][4] = {
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21}
    };
    char cutleryAnswer[][MAX_CUTLERY_NAME] = {"Yes!", "No, thanks!"}, additionalInfo[50], drinks[][MAX_DRINK_NAME] = { "Coca-Cola", "Fanta", "Lipton", "Water", "No, thanks!"};
    while (!orderConfirmed) {
        switch (state) {
            case 0: {
                inputAccountData(username, password);
                state++;
                break;
            }
            case 1: {
                displayFoodOptions(noOfFoodTypes, foodTypes);
                foodTypeChoice = getChoiceIndex(foodTypes, &state);
                break;
            }
            case 2: {
                displaySpecificFoodOptions(noOfDishes[foodTypeChoice], foodTypes[foodTypeChoice], food[foodTypeChoice], prices[foodTypeChoice]);
                specificFoodChoice = getChoiceIndex(food[foodTypeChoice], &state);
                break;
            }
            case 3: {
                displayDrinksOptions(noOfDrinks, foodTypes[foodTypeChoice], drinks, drinksPrices);
                drinkChoice = getChoiceIndex(drinks, &state);
            }
            case 4: {
                displayCutleryOptions(cutlery, cutleryAnswer);
                cutleryChoice = getChoiceIndex(cutleryAnswer, &state);
            }
            case 5: {
                getAdditionalInfo(additionalInfo, &state);
                break;
            }
            case 6: {
                displayAccountData(username);
                displayCustomerOrder(food[foodTypeChoice][specificFoodChoice], prices[foodTypeChoice][specificFoodChoice], drinks[drinkChoice], drinksPrices[drinkChoice], cutleryAnswer[cutleryChoice], additionalInfo);
                orderConfirmed = getFinalOrderChoiceIndex(&state, username);
                break;
            }
        }
    }
    return 0;
}

void getAdditionalInfo(char additionalInfo[], int *state) {
    printf("Any additional info? \n");
    gets(additionalInfo);
    (*state)++;
}
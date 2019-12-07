//
// Created by Denisa on 11/4/2019.
//
#include <stdio.h>
#include <string.h>

void displayAccountData(char username[]) {
    printf("This is your order: \n \n");
    printf("Name: %s \n", username);
}

void displayCustomerOrder(char * specificFoods, double prices, char * drinks, double drinksPrices, char cutleryAnswer[], char additionalInfo[], int drinkChoice) {
    printf("Food items: \n");
    printf("--- %s: %.2lf \n", specificFoods, prices);
    if (drinkChoice + 'a' == 'e') {
        printf("--- Drinks: %s \n", "No, thanks!");
    } else {
        printf("--- Drinks: %s: %.2lf \n", drinks, drinksPrices);
    }
    printf("Cutlery: %s \n", cutleryAnswer);
    if (strcmp(additionalInfo, "")!=0)
        printf("Additional info: %s \n", additionalInfo);
    if (drinkChoice + 'a' == 'e') {
        printf("Payment amount: %.2lf \n", prices);
    } else {
        printf("Payment amount: %.2lf \n", prices + drinksPrices);
    }
    printf("\n");
}
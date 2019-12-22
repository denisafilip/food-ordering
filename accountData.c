//
// Created by Denisa on 11/4/2019.
//
#include <stdio.h>
#include <string.h>
#include "accountData.h"

void displayAccountData(char username[]) {
    printf("This is your order: \n \n");
    printf("Name: %s \n", username);
}

void displayCustomerOrder(char * specificFoods, double prices, drinks * d, cutlery c, char additionalInfo[], int drinkChoice) {
    printf("Food items: \n");
    printf("--- %s: %.2lf \n", specificFoods, prices);
    if (drinkChoice + 'a' == 'e') {
        printf("--- Drinks: %s \n", "No, thanks!");
    } else {
        printf("--- Drinks: %s: %.2lf \n", d->name, d->price);
    }
    printf("Cutlery: %s \n", *(c.cutleryAnswer));
    if (strcmp(additionalInfo, "")!=0)
        printf("Additional info: %s \n", additionalInfo);
    if (drinkChoice + 'a' == 'e') {
        printf("Payment amount: %.2lf \n", prices);
    } else {
        printf("Payment amount: %.2lf \n", prices + d->price);
    }
    printf("\n");
}
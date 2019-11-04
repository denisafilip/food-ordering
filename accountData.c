//
// Created by Denisa on 11/4/2019.
//
#include <stdio.h>
#include <string.h>

#define MAX_SPECIFIC_FOOD_NAME 20
#define MAX_DRINK_NAME 30
#define MAX_CUTLERY_NAME 30


void inputAccountData(char username[], char password[]) {
    printf("Please sign in to continue: \n");
    printf("username \n");
    gets(username);
    printf("password \n");
    gets(password);
}

void displayAccountData(char username[]) {
    printf("This is your order: \n \n");
    printf("Name: %s \n", username);
}

void displayCustomerOrder(char food[], int prices, char drinks[], int drinksPrices, char cutleryAnswer[], char additionalInfo[]) {
    int drinkChoice;
    printf("Food items: \n");
    printf("--- %s: %d \n", food, prices);
    if (drinkChoice + 'a' == 'e') {
        printf("--- Drinks: %s \n", drinks);
    }
    else {
        printf("--- Drinks: %s: %d \n", drinks, drinksPrices);
    }
    printf("Cutlery: %s \n", cutleryAnswer);
    if (strcmp(additionalInfo, "")!=0)
        printf("Additional info: %s \n", additionalInfo);
    printf("Payment amount: %d \n", prices + drinksPrices);
    printf("\n");
}
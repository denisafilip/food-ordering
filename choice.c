//
// Created by Denisa on 11/4/2019.
//
#include <stdio.h>

int getChoiceIndex(int noOfChoices, int *state) {
    int choiceIndex;
    char choice = getchar();
    getchar();
    if (choice == 'a' + noOfChoices) {
        (*state)--;
    }
    else {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}

int getFinalOrderChoiceIndex(int *state, char username[]) {
    int orderConfirmed = 0;
    printf("a) Confirm order \n");
    printf("b) Go back \n");
    char choice = getchar();
    if (choice == 'a') {
        orderConfirmed = 1;
        printf("Order confirmed! Thank you for buying from us, %s! \n", username);
    }
    else {
        (*state)-=2;
    }
    getchar();
    return orderConfirmed;
}

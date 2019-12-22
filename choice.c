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
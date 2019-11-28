//
// Created by Denisa on 11/28/2019.
//

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "loadData.h"

int countSpecificFoods(int * noOfSpecificFoods, char line[], int index) {
    noOfSpecificFoods[index]=0;
    for (int j=0; j<strlen(line); j++) {
        if (line[j] == '(') noOfSpecificFoods[index]++; //count the noOfSpecificFoods for each foodType
    }
    return noOfSpecificFoods[index];
}

void substractCharPrice(const char *delimiter, int index, char charPrice[]) {
    for (int i=0; i<255; i++) {
        charPrice[i]='\0';
    }
    int m = 0;
    while (delimiter[index] != '\0') {
        if (isdigit(delimiter[index])) {
            charPrice[m] = delimiter[index];
            m++;
        }
        index++;
    }
    charPrice[m+1] = '\0';
}

void substractSpecificFood(const char *delimiter, char *** specificFoods, int indexColumn, int indexRow, int index) {
    while (delimiter[index] != '-') {
        specificFoods[indexRow][indexColumn][index] = delimiter[index];
        index++;
    }
    specificFoods[indexRow][indexColumn][index-1] = '\0';
}

void substractSpecificDrink(const char *delimiter, char ** drinks, int indexRow, int index) {
    while (delimiter[index] != '-' || delimiter[index+1] != ' ') {
        drinks[indexRow][index] = delimiter[index];
        index++;
    }
    drinks[indexRow][index-1] = '\0';
}

void cutName(int index, char ** foodTypes) {
    char *correctName = strchr(foodTypes[index], ':');
    foodTypes[index][correctName-foodTypes[index]] = '\0';
}

void delimitingLineFood(char * line, char ** foodTypes, int index, char *** specificFoods, double ** prices, char * charPrice) {
    char *foodNameDelim = strtok(line, "()");
    strcpy(foodTypes[index], foodNameDelim);
    cutName(index, foodTypes);
    int k=0;
    foodNameDelim = strtok(NULL, "()");
    while (foodNameDelim != NULL) {
        if (strcmp(foodNameDelim, " ") != 0 && strcmp(foodNameDelim, "\n") != 0){
            specificFoods[index][k] = (char*)malloc(MAX_SPECIFIC_FOOD_NAME * sizeof(char));
            int j = 0;
            substractSpecificFood(foodNameDelim, specificFoods, k, index, j);
            substractCharPrice(foodNameDelim, j, charPrice);
            prices[index][k] = atof(charPrice)/100;
            k++;
        }
        foodNameDelim = strtok(NULL, "()");
    }
}

void delimitingLineDrinks(char * line, char ** drinks, char * charPrice, double * pricesDrinks) {
    int i=0;
    char *drinkNameDelim = strtok(line, "()");
    while (drinkNameDelim != NULL) {
        if (strcmp(drinkNameDelim, "\n") != 0 && strcmp(drinkNameDelim, ", ") != 0) {
            drinks[i] = (char*)malloc(MAX_DRINK_NAME * sizeof(char));
            int j = 0;
            substractSpecificDrink(drinkNameDelim, drinks, i, j);
            substractCharPrice(drinkNameDelim, j, charPrice);
            pricesDrinks[i] = atof(charPrice);
            i++;
        }
        drinkNameDelim = strtok(NULL, "()");
    }
}


int getNumberOf(char * charNumber, char * line, FILE *data) {
    fgets(line, MAX_LINE, data);
    charNumber = strtok(line,":");
    return atoi(charNumber);
}
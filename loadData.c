//
// Created by Denisa on 11/28/2019.
//

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "loadData.h"
#include "extraAssignment3.h"

//change
int countSpecificFoods(int * noOfSpecificFoods, char * line, int index) {
    noOfSpecificFoods[index]=0;
    for (int j=0; j<strlen(line); j++) {
        if (line[j] == '(') noOfSpecificFoods[index]++; //count the noOfSpecificFoods for each foodType
    }
    return noOfSpecificFoods[index];
}

void constructCharPrice(char *delimiter, int index, char * charPrice) {
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

char * constructSpecificProductX(char *delimiter, int index) {
    char * nameOfProduct = (char*)malloc(MAX_LINE * sizeof(char));
    while (delimiter[index] != '-' || delimiter[index+1] != ' ') {
        nameOfProduct[index] = delimiter[index];
        index++;
    }
    nameOfProduct[index-1] = '\0';
    return nameOfProduct;
}

void cutName(int index, char ** foodTypes) {
    char *correctName = strchr(foodTypes[index], ' ');
    foodTypes[index][correctName-foodTypes[index]] = '\0';
}

void delimitingLineFood(char * line, char ** foodTypes, int index, char *** specificFoods, double ** prices, char * charPrice) {
    char *foodNameDelim = strtok(line, "()");
    strcpy(foodTypes[index], foodNameDelim);
    cutName(index, foodTypes);
    int k=0;
    foodNameDelim = strtok(NULL, "()");
    while (foodNameDelim != NULL) {
        if (strcmp(foodNameDelim, " ") != 0 && strcmp(foodNameDelim, "\n") != 0 && strcmp(foodNameDelim, ", ") != 0) {
            specificFoods[index][k] = (char*)malloc(MAX_SPECIFIC_FOOD_NAME * sizeof(char));
            int j = 0;
            specificFoods[index][k] = constructSpecificProductX(foodNameDelim, j);
            constructCharPrice(foodNameDelim, j, charPrice);
            prices[index][k] = atof(charPrice)/100;
            k++;
        }
        foodNameDelim = strtok(NULL, "()");
    }
}

int getNumberOf(char * charNumber, char * line, FILE *data) {
    fgets(line, MAX_LINE, data);
    charNumber = strtok(line, ":");
    return atoi(charNumber);
}
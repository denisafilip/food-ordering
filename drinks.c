//
// Created by Denisa on 12/22/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "drinks.h"
#include "extraAssignment3.h"
#include "loadData.h"

char * constructSpecificProduct(char *delimiter, int index, drinks * item) {
    item->name = (char*)malloc(MAX_LINE * sizeof(char));
    while (delimiter[index] != '-' || delimiter[index+1] != ' ') {
        item->name[index] = delimiter[index];
        index++;
    }
    item->name[index-1] = '\0';
    return item->name;
}

void delimitingLineDrinks(char * line, char * charPrice, drinks * d) {
    int i=0;
    char *drinkNameDelim = strtok(line, "()");
    while (drinkNameDelim != NULL) {
        if (strcmp(drinkNameDelim, "\n") != 0 && strcmp(drinkNameDelim, ", ") != 0 && strcmp(drinkNameDelim, " ") != 0) {
            d[i].name = (char*)malloc(MAX_DRINK_NAME * sizeof(char));
            int j = 0;
            d[i].name = constructSpecificProduct(drinkNameDelim, j, d);
            constructCharPrice(drinkNameDelim, j, charPrice);
            d[i].price = atof(charPrice);
            i++;
        }
        drinkNameDelim = strtok(NULL, "()");
    }
}

void displayDrinksOptions(int noOfDrinks, char * foodTypes, drinks * d) {
    printf("Please choose a drink to go with your %s \n", foodTypes);
    for (int i=0; i<noOfDrinks; i++) {
        putchar('a' + i);
        printf(") %s: %.2lf \n", d[i].name, d[i].price);
    }
    printf("%c) %s \n", 'a' + noOfDrinks, "No, thanks!");
    printf("%c) Go Back \n", 'a' + noOfDrinks + 1);
}

void freeDrinkMemory(int noOfDrinks, drinks * d) {

    for (int i=0; i<noOfDrinks; i++) {
        free(&(d->name[i]));
    }
    free(d->name);
}
//
// Created by Denisa on 12/20/2019.
//
#include <stdio.h>
#include "cutlery.h"
#include <stdlib.h>

cutlery createCutlery() {
    cutlery c;
    c.cutleryAnswer = (char**)malloc(MAX_CUTLERY_NAME * sizeof(char*));
    c.cutleryAnswer[0] = "Yes!";
    c.cutleryAnswer[1] = "No, thanks!";
    return c;
}

void displayCutleryOptions(int cutleryValue, cutlery c) {
    printf("Do you want cutlery? \n");
    for (int i=0; i < cutleryValue; i++) {
        putchar('a' + i);
        printf(") %s \n", c.cutleryAnswer[i]);
    }
    printf("%c) Go Back \n", 'a' + cutleryValue);
}

void freeCutlery(cutlery * c) {
    free(c->cutleryAnswer);
}
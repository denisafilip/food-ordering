//
// Created by Denisa on 12/20/2019.
//

#include "extraAssignment3.h"
#include "encryption.h"
#include <stdio.h>
#include <stdlib.h>

user createUser() {
    user u;
    u.username = (char*)malloc(MAX_USERNAME * sizeof(char));
    u.password = (char*)malloc(MAX_PASSWORD * sizeof(char));
    return u;
}

int getFinalOrderChoiceIndex(int *state, user u) {
    int orderConfirmed = 0;
    printf("a) Confirm order \n");
    printf("b) Go back \n");
    char choice = getchar();
    if (choice == 'a') {
        orderConfirmed = 1;
        printf("Order confirmed! Thank you for buying from us, %s! \n", u.username);
    }
    else {
        (*state)-=2;
    }
    getchar();
    return orderConfirmed;
}

void freeUserData(user * u) {
    free(u->username);
    free(u->password);
}
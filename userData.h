//
// Created by Denisa on 12/20/2019.
//

#ifndef FOOD_ORDERING_USERDATA_H
#define FOOD_ORDERING_USERDATA_H

#endif //FOOD_ORDERING_USERDATA_H

typedef struct _user {
    char * username;
    char * password;
} user;

user createUser();
int getFinalOrderChoiceIndex(int *state, user u);
void freeUserData(user * u);
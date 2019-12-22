//
// Created by Denisa on 12/6/2019.
//



#ifndef FOOD_ORDERING_EXTRAASSIGNMENT3_H
#define FOOD_ORDERING_EXTRAASSIGNMENT3_H

#include <stdio.h>
#include <stdbool.h>
#include "userData.h"

#define LOAD_DATA "Please load the data:"
#define ERROR_PASSWORD_LONG	"The password must be at least 7 chars long"
#define ERROR_PASSWORD_NOT_USERNAME	"The password must not contain the username"
#define ERROR_PASSWORD_SPECIAL_CHAR	"The password must contain one of the following characters: {'.','_','!'}"
#define ERROR_PASSWORD_DIGITS	"The password must contain digits"
#define SIGN_IN_UP	"Do you want to sign in or sign up?"
#define SIGN_IN	"Sign in"
#define SIGN_UP	"Sign up"
#define SIGNING_IN	"Signing in!"
#define SIGNING_UP	"Signing up!"
#define USER_NOT_FOUND	"Username doesn't exist"
#define DUPLICATE_USER	"Please choose another username!"
#define INCORRECT_PASSWORD	"Incorrect password"
#define MAX_USERNAME 20
#define MAX_PASSWORD 15
#define MAX_USERS 30
#define MAX_LINE 255

typedef struct {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
} userFromFile;

void inputAccountData(user * u);
void writeInFile(FILE* signInUp, int noOfUsers);
void rememberUsers(char line[MAX_LINE], FILE* signInUp, userFromFile * users, int * noOfUsers);
void chooseSignInUp(int *signState, int *signChoice);
void inputFromUser(int signChoice, int *signState, user u);
void loginProcess(user u, int *state);
void addUser(userFromFile * users, int *noOfUsers, user u, FILE* signInUp, int *signedIn);
void checkUsername(userFromFile * users, user * u, int *signChoice, int noOfUsers);
void validateLengthPassword(user u, bool *isOk);
void validateDigitsPassword(user u, bool *isOk);
void validateSpecialCharsPassword(user u, bool *isOk);
void validateNotUsernamePassword(user u, bool *isOk);
void validatePassword(user * u, bool *isOk);
void signIn(userFromFile * users, int noOfUsers, user u, int *signState, int *signedIn, int *state);
void signUpFunctionality(user * u, userFromFile * users, int *noOfUsers, FILE* signInUp, int *state);

#endif //FOOD_ORDERING_EXTRAASSIGNMENT3_H

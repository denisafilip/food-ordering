//
// Created by Denisa on 12/6/2019.
//

#include <stdio.h>
#include <stdbool.h>
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

#ifndef FOOD_ORDERING_EXTRAASSIGNMENT3_H
#define FOOD_ORDERING_EXTRAASSIGNMENT3_H

#endif //FOOD_ORDERING_EXTRAASSIGNMENT3_H
typedef struct {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
} userFromFile;

void inputAccountData(char username[MAX_USERNAME], char password[MAX_PASSWORD]);
void rememberUsers(char line[MAX_LINE], FILE* signInUp, userFromFile * users, int * noOfUsers);
void chooseSignInUp(int *signState, int *signChoice);
void inputFromUser(int signChoice, int *signState, char * username, char * password);
void loginProcess(char * username, char * password, int *state);
void addUser(userFromFile * users, int *noOfUsers, char username[MAX_USERNAME], char password[MAX_PASSWORD], FILE* signInUp, int *signedIn);
void checkUsername(userFromFile * users, char username[MAX_USERNAME], int *signChoice, int noOfUsers);
void validateLengthPassword(char password[MAX_PASSWORD], bool *isOk);
void validateDigitsPassword(char password[MAX_PASSWORD], bool *isOk);
void validateSpecialCharsPassword(char password[MAX_PASSWORD], bool *isOk);
void validateNotUsernamePassword(char password[MAX_PASSWORD], char username[MAX_USERNAME], bool *isOk);
void validatePassword(char password[MAX_PASSWORD], char username[MAX_USERNAME], bool *isOk);
void signIn(userFromFile * users, int noOfUsers, char username[MAX_USERNAME], char password[MAX_PASSWORD], int *signState, int *signedIn, int *state);
void signUpFunctionality(char username[MAX_USERNAME], char password[MAX_PASSWORD], userFromFile * users, int *noOfUsers, FILE* signInUp, int *state);
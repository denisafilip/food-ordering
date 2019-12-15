//
// Created by Denisa on 12/6/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "extraAssignment3.h"
#include "accountData.h"
#include "encryption.h"

void inputAccountData(char username[MAX_USERNAME], char password[MAX_PASSWORD]) {
    printf("username \n");
    gets(username);
    printf("password \n");
    gets(password);
}

void rememberUsers(char line[], FILE* signInUp, userFromFile * users, int * noOfUsers) {
   fgets(line, MAX_LINE, signInUp);
   fgets(line, MAX_LINE, signInUp);
    while(fgets(line, MAX_LINE, signInUp)) {
        char *delim = strtok(line, " ");
        strcpy(users[*noOfUsers].username, delim);
        delim = strtok(NULL, "\n");
        decryptingPassword(delim, 3);
        strcpy(users[*noOfUsers].password, delim);
        int i=0;
        while (delim[i] != '\n' && delim[i] != '\0') {
            i++;
        }
        users[*noOfUsers].password[i] = '\0';
        (*noOfUsers)++;
    }
}

void writeInFile(FILE* signInUp, int noOfUsers) {
    char * key = "Julius Caesar Cipher: the letters and numbers are shifted to the right by the shiftKey";
    fopen("signInUp", "r+");
    fseek(signInUp, 0, SEEK_SET);
    fprintf(signInUp, "%s\n", key);
    fseek(signInUp, 88, SEEK_SET);
    fprintf(signInUp, "%d", noOfUsers);
    fclose(signInUp);
}

void addUser(userFromFile * users, int *noOfUsers, char username[MAX_USERNAME], char password[MAX_PASSWORD], FILE* signInUp, int *signedIn) {
    strcpy(users[*noOfUsers].username, username);
    strcpy(users[*noOfUsers].password, password);
    encryptPassword(password, 3);
    (*noOfUsers)++;
    writeInFile(signInUp, *noOfUsers);
    fopen("signInUp", "a+");
    fprintf(signInUp, "\n%s %s", username, password);
    *signedIn = 1;
}

void checkUsername(userFromFile * users, char username[MAX_USERNAME], int *signChoice, int noOfUsers) {
    for (int i=0; i<noOfUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf(DUPLICATE_USER "\n");
            gets(username);
            *signChoice = 1;
        }
    }
}

void chooseSignInUp(int *signState, int *signChoice) {
    printf(SIGN_IN_UP "\n");
    putchar('a' + 0);
    printf(")" SIGN_IN "\n");
    putchar('a' + 1);
    printf(")" SIGN_UP "\n");
    (*signState)++;
    int c = getchar();
    getchar();
    *signChoice = c - 'a' + 1;
}

void inputFromUser(int signChoice, int *signState, char * username, char * password) {
    if (signChoice == 1) {
        printf(SIGNING_IN "\n");
    } else printf(SIGNING_UP "\n");
    inputAccountData(username, password);
    (*signState) += signChoice;
}

void validatePassword(char password[MAX_PASSWORD], char username[MAX_USERNAME], bool *isOk) {
    validateLengthPassword(password, isOk);
    validateDigitsPassword(password, isOk);
    validateSpecialCharsPassword(password, isOk);
    validateNotUsernamePassword(password, username, isOk);
}

void validateLengthPassword(char password[MAX_PASSWORD], bool *isOk) {
    if (strlen(password) < 7 && *isOk == true) {
        printf(ERROR_PASSWORD_LONG "\n");
        gets(password);
        *isOk = false;
    }
}

void validateDigitsPassword(char password[MAX_PASSWORD], bool *isOk) {
    bool ok = false;
    for (unsigned int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) ok = true;
    }
    if (ok == false && *isOk == true) {
        printf(ERROR_PASSWORD_DIGITS "\n");
        gets(password);
        *isOk = false;
    }
}

void validateSpecialCharsPassword(char password[MAX_PASSWORD], bool *isOk) {
    if (strchr(password, '_') == 0 && strchr(password, '.') == 0 && strchr(password, '!') == 0 && *isOk == true) {
        printf(ERROR_PASSWORD_SPECIAL_CHAR "\n");
        gets(password);
        *isOk = false;
    }
}

void validateNotUsernamePassword(char password[MAX_PASSWORD], char username[MAX_USERNAME], bool *isOk) {
    if (strstr(password, username) != 0 && *isOk == true) {
        printf(ERROR_PASSWORD_NOT_USERNAME "\n");
        gets(password);
        *isOk = false;
    }
}

void signIn(userFromFile * users, int noOfUsers, char username[MAX_USERNAME], char password[MAX_PASSWORD], int *signState, int *signedIn, int *state) {
    for (int i=0; i<noOfUsers; i++) {
        if (strcmp(users[i].username, username) != 0 && i == noOfUsers - 1) {
            printf(USER_NOT_FOUND "\n");
            *signState = 0;
            break;
        } else if (strcmp(users[i].username, username) == 0) {
            if (strcmp(users[i].password, password) != 0) {
                printf(INCORRECT_PASSWORD "\n");
                *signState = 1;
                break;
            } else if (strcmp(users[i].password, password) == 0) {
                *signedIn = 1;
                (*state)++;
                 break;
            }
        }
    }
}

void signUpFunctionality(char username[MAX_USERNAME], char password[MAX_PASSWORD], userFromFile * users, int *noOfUsers, FILE* signInUp, int *state) {
    int signChoice = 0, signState = 0;
    int signedIn = 0;
    while (!signedIn) {
        switch(signState) {
            case 0: {
                chooseSignInUp(&signState, &signChoice);
                break;
            }
            case 1: {
                inputFromUser(signChoice, &signState, username, password);
                break;
            }
                // Sign In
            case 2: {
                signIn(users, *noOfUsers, username, password, &signState, &signedIn, *(&state));
                break;
            }
                //Sign Up
            case 3: {
                bool isOk = true;
                checkUsername(users, username, &signChoice, *noOfUsers);
                validatePassword(password, username, &isOk);
                if (isOk == false) {
                    break;
                }
                addUser(users, *(&noOfUsers), username, password, signInUp, &signedIn);
                (*state)++;
                break;
            }
        }
    }
}

void loginProcess(char username[MAX_USERNAME], char password[MAX_PASSWORD], int *state) {
    int noOfUsers = 0;
    char * line = (char*)malloc(MAX_LINE * sizeof(char));
    userFromFile * users = (userFromFile*)malloc(MAX_USERS * sizeof(userFromFile));
    FILE *signInUp = fopen("signInUp", "r+");
    if (signInUp == NULL) {
        printf("Sorry, the file you were looking for does not exist \n");
    }
    rememberUsers(line, signInUp, users, &noOfUsers);
    signUpFunctionality(username, password, users, &noOfUsers, signInUp, *(&state));
    fclose(signInUp);
}

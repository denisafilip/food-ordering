//
// Created by Denisa on 12/10/2019.
//
#include <string.h>
#include <ctype.h>
#include <stdio.h>

//Iulius Caesar Cipher
void encryptPassword(char message[], int shiftKey) {
   char ch;
    for (unsigned int i = 0; i < strlen(message); i++) {
        ch = message[i];
        if (islower(ch)) {
            ch = ch + shiftKey;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        } else if (isdigit(ch)) {
            ch = ch + shiftKey;
            if (ch > '9') {
                ch = ch - '9' + '0' - 1;
            }
            message[i] = ch;
        }
    }
}

void decryptingPassword(char message[], int shiftKey) {
    char ch;
    for (unsigned int i = 0; i < strlen(message); i++) {
        ch = message[i];
        if (islower(ch)) {
            ch = ch - shiftKey;
            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        } else if (isdigit(ch)) {
            ch = ch - shiftKey;
            if (ch < '0') {
                ch = ch + '9' - '0' + 1;
            }
            message[i] = ch;
        }
    }
}
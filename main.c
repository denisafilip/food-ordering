#include <stdio.h>

int main() {
    printf("Welcome to Food Thingies! \n");
    char username[20], password[20];
    int noOfFoodTypes = 3, choice, foodTypeChoice;
    char foodTypes[][30] = {"Pizza", "Pasta", "Salad"};
    char food[3][3][20] = {
            {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
            {"Chicken Alfredo", "Mac & Cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}
    };
    int noDishes[] = {3, 2, 4};
    double prices[3][3] = {
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21}
    };

    int state = 0;
    int orderConfirmed = 0;
    while (!orderConfirmed) {
        switch (state) {
            case 0: {
                printf("Please sign in to continue: \n");

                printf("username \n");
                gets(username);
                printf("password \n");
                gets(password);
                state++;
                break;
            }
            case 1: {
                printf("Please choose the food you feel like eating today: \n");
                for (int i=0; i<noOfFoodTypes; i++) {
                    putchar('a' + i);
                    printf(") %s \n", foodTypes[i]);
                }
                printf("%c) Go Back \n", 'a' + noOfFoodTypes);
                choice = getchar();
                getchar();
                if (choice == 'a' + noOfFoodTypes) {
                    state--;
                    break;
                }
                foodTypeChoice = choice - 'a';
                state++;
                break;
            }
            case 2: {
                printf("Please choose the type of %s \n", foodTypes[foodTypeChoice]);
                for (int i=0; i<noOfFoodTypes; i++) {
                    putchar('a' + i);
                    printf(") %s: %.2f \n", food[foodTypeChoice][i], prices[foodTypeChoice][i]);
                }
                printf("%c) Go Back \n", 'a' + noDishes[foodTypeChoice]);
                choice = getchar();
                getchar();
                if (choice == 'a' + noDishes[foodTypeChoice]) {
                    state--;
                    break;
                }
                foodTypeChoice = choice - 'a';
                state++;
                break;
            }
        }
    }


    return 0;
}
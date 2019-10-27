#include <stdio.h>

int main() {
    printf("Welcome to Food Thingies! \n");
    char username[20], password[20];
    int noOfFoodTypes = 3, choice, foodTypeChoice, specificFoodChoice, drinkChoice;
    char foodTypes[][30] = {"Pizza", "Pasta", "Salad"};
    char food[3][4][20] = {
            {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
            {"Chicken Alfredo", "Mac & Cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}
    };
    int noOfDrinks = 5;
    char drinks[][30] = { "Coca-Cola", "Fanta", "Lipton", "Water", "No, thanks!"};
    int drinksPrices[] = {5, 5, 5, 4};
    int noOfDishes[] = {3, 2, 4};
    int prices[3][3] = {
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21}
    };
    int cutlery = 2, cutleryChoice;
    char cutleryAnswer[][30] = {"Yes!", "No, thanks!"};
    char additionalInfo[50];

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
                for (int i=0; i<noOfDishes[foodTypeChoice]; i++) {
                    putchar('a' + i);
                    printf(") %s: %d \n", food[foodTypeChoice][i], prices[foodTypeChoice][i]);
                }
                printf("%c) Go Back \n", 'a' + noOfDishes[foodTypeChoice]);
                choice = getchar();
                getchar();
                if (choice == 'a' + noOfDishes[foodTypeChoice]) {
                    state--;
                    break;
                }
                specificFoodChoice = choice - 'a';
                state++;
                break;
            }

            case 3: {
                printf("Please choose a drink to go with your %s \n", foodTypes[foodTypeChoice]);
                for (int i=0; i<noOfDrinks-1; i++) {
                    putchar('a' + i);
                    printf(") %s: %d \n", drinks[i], drinksPrices[i]);
                }
                printf("%c) %s \n", 'a' + noOfDrinks - 1, drinks[4]);
                printf("%c) Go Back \n", 'a' + noOfDrinks);
                choice = getchar();
                getchar();
                if (choice == 'a' + noOfDrinks) {
                    state--;
                    getchar();
                    break;
                }
                drinkChoice = choice - 'a';
                state++;
                break;
            }

            case 4: {
                printf("Do you want cutlery? \n");
                for (int i=0; i < cutlery; i++) {
                    putchar('a' + i);
                    printf(") %s \n", cutleryAnswer[i]);
                }
                printf("%c) Go Back \n", 'a' + cutlery);
                choice = getchar();
                getchar();
                if (choice == 'a' + cutlery) {
                    state--;
                    break;
                }
                cutleryChoice = choice - 'a';
                state++;
                break;
            }

            case 5: {
                printf("Any additional info? \n");
                scanf("%s", additionalInfo);
                /*printf("a) Go back \n");
                choice = getchar();
                getchar();
                if (choice == 'a') {
                    state--;
                    break;
                }*/
                state++;
                break;

            }

            case 6: {
                //order
                printf("This is your order: \n \n");
                printf("Name: %s \n", username);
                printf("Food items: \n");
                printf("--- %s: %d \n", food[foodTypeChoice][specificFoodChoice], prices[foodTypeChoice][specificFoodChoice]);
                printf("--- %s: %d \n", drinks[drinkChoice], drinksPrices[drinkChoice]);
                printf("Cutlery: %s \n", cutleryAnswer[cutleryChoice]);
                printf("Additional info: %s \n", additionalInfo);
                printf("Payment amount: %d \n", prices[foodTypeChoice][specificFoodChoice] + drinksPrices[drinkChoice]);
                printf("\n");
                printf("a) Confirm order \n");
                printf("b) Go back \n");
                choice = getchar();
                getchar();
                if (choice == 'a') {
                    orderConfirmed = 1;
                    printf("Order confirmed! Thank you for buying from us, %s! \n", username);
                    break;
                }
                else {
                    state=state-2;

                }
                getchar();
                break;
            }
        }
    }
    return 0;
}
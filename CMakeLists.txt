cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food_ordering main.c display.h display.c choice.h choice.c accountData.h accountData.c loadData.c loadData.h freeMemory.c freeMemory.h extraAssignment3.c extraAssignment3.h encryption.h encryption.c userData.c userData.h foods.c foods.h drinks.c drinks.h)
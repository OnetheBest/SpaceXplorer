#include "title.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>

Difficulty titleScreen() {
    int diff;
        printf("\nChoose your difficulty:\n");
        printf("1. Easy\n");
        printf("2. Normal\n");
        printf("3. Hard\n");
        printf("4. Nightmare\n");
        diff = _getch() - '0';
    fflush(stdin);
    return (Difficulty) diff;

}

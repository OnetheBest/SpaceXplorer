#include "title.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "scores.h"

Difficulty titleScreen() {
    int highScore, lastScore;
    loadScores(&highScore, &lastScore);
    int diff;
        printf("==================================");
        printf("           SPACE XPLORER          ");
        printf("==================================\n");
        printf("\nHigh Score : %d\n", highScore);
        printf("Last Score : %d\n", lastScore);
        printf("\nChoose your difficulty:\n");
        printf("1. Easy\n");
        printf("2. Normal\n");
        printf("3. Hard\n");
        printf("4. Nightmare\n");
        diff = _getch() - '0';
    fflush(stdin);
    return (Difficulty) diff;
}

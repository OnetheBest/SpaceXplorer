#include "title.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "scores.h"

void showTutorial() {
    system("cls");
    printf("=== TUTORIAL ===\n");
    printf("- Use W A S D to move.\n");
    printf("- Press E to fire a bullet (if you have one).\n");
    printf("- Collect ! for bullet and + for fuel.\n");
    printf("- Avoid enemies (V), or shoot them for +100 points.\n");
    printf("- Press I to open your inventory(player stats).\n");
    printf("- Score increases over time.\n");
    printf("- Game ends if you run out of fuel or health.\n");
    printf("\nPress any key to return to title screen...");
    _getch();
}

Difficulty titleScreen() {
    int highScore, lastScore;
    loadScores(&highScore, &lastScore);
    int diff;

    while(1){
        system("cls");
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
    printf("5. Tutorial");
    diff = _getch() - '0';

    if (diff >= 1 && diff <= 4) {
        return (Difficulty) diff;
    } else if (diff == 5) {
        showTutorial();
    }
}}
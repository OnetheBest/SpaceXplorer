#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "entity.h"
#include "input.h"
#include "game.h"
#include "title.h"




int main() {
    Difficulty difficulty = titleScreen();
    int speed = 10;
    Player player = {{GRID_SIZE / 2, GRID_SIZE - 3}, 3, 100};
    applyDifficulty(player, difficulty, &speed);
    Enemy enemies[MAX_ENEMIES];
    spawnEnemies(enemies, MAX_ENEMIES);
    int move;

    while(1) {
        srand(time(NULL));
        int xpos = rand() % 18;
        if (player.pos.y < GRID_SIZE) {system("cls");}
        drawGrid(player, enemies, MAX_ENEMIES);
        Controller(&player);
        if (move % speed == 0) {
            moveEnemies(enemies, MAX_ENEMIES);
        }
        printf("\nLives: %d || Fuel: %d", player.health, player.fuel);
        move++;
        Sleep(1);
    }
    return 0;
}

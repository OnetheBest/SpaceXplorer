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
    Enemy enemies[MAX_ENEMIES];
    Difficulty difficulty = titleScreen();
    Sleep(400);
    int speed = 10;
    Player player = {{GRID_SIZE / 2, GRID_SIZE - 3}, 3, 100};
    applyDifficulty(&player, difficulty, &speed);
    spawnEnemies(enemies, MAX_ENEMIES);
    int move;
    int deplete;
    int pause = 0;
    while(1) {
        srand(time(NULL));
        if (player.pos.y < GRID_SIZE) {system("cls");}
        drawGrid(player, enemies, MAX_ENEMIES);
        Controller(&player);
        if (move % speed == 0) {
            if (pause == 0) {
                Sleep(500);
                pause = 1;
            }
                moveEnemies(enemies, MAX_ENEMIES);
            depleteFuel(&player);
        }
        printf("\nLives: %d || Fuel: %d", player.health, player.fuel);
        move++;
        deplete++;
        Sleep(10);
    }
    return 0;
}

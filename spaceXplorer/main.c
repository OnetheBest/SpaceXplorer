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
    Collectible collectibles[MAX_COLLECTIBLES];
    Difficulty difficulty = titleScreen();
    Sleep(400);
    int speed = 10;
    Player player = {{GRID_SIZE / 2, GRID_SIZE - 3}, 3, 100};
    Enemy enemies[MAX_ENEMIES];
    Bullet bullet = {{0, 0}, 0};
    applyDifficulty(&player, difficulty, &speed);
    spawnEnemies(enemies, MAX_ENEMIES);
    spawnCollectibles(collectibles, MAX_COLLECTIBLES);
    int move;
    int deplete;
    int pause = 0;
    while(1) {
        srand(time(NULL));
        if (player.pos.y < GRID_SIZE) {system("cls");}
        if (bullet.active) {
            bullet.pos.y--;

            // If bullet reaches top, deactivate
            if (bullet.pos.y < 0) {
                bullet.active = 0;
            }

            // Check collision with enemies
            for (int i = 0; i < MAX_ENEMIES; i++) {
                if (enemies[i].spawned &&
                    enemies[i].pos.x == bullet.pos.x &&
                    enemies[i].pos.y == bullet.pos.y) {
                    enemies[i].spawned = 0;
                    bullet.active = 0;
                    break;
                }
            }
        }
        drawGrid(player, enemies, MAX_ENEMIES, collectibles, MAX_COLLECTIBLES, bullet);
        Controller(&player, &bullet);
        if (move % speed == 0) {
            if (pause == 0) {
                Sleep(500);
                pause = 1;
            }
            moveEnemies(enemies, MAX_ENEMIES, collectibles, MAX_COLLECTIBLES);

            depleteFuel(&player);
        }

        //logic to be moved
        collectPowerups(&player, collectibles);


        printf("\nLives: %d || Fuel: %d", player.health, player.fuel);
        move++;
        deplete++;
        Sleep(10);
    }
    return 0;
}

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
    int game = 1;
    while (game = 1) {
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
        int count;
        int pause = 0;
        int score = 0;
        while (game != 0) {
            srand(time(NULL));
            system("cls");
            Controller(&player, &bullet);

            if (move % speed == 0) {
                if (pause == 0) {
                    Sleep(500);
                    pause = 1;
                }
                moveEnemies(enemies, MAX_ENEMIES, collectibles, MAX_COLLECTIBLES);
                score += 1;
                depleteFuel(&player);
            }

            bulletBehaviour(&bullet, enemies, &score);

            collectPowerups(&player, collectibles);


            drawGrid(player, enemies, MAX_ENEMIES, collectibles, MAX_COLLECTIBLES, bullet);


            printf("\nLives: %d || Fuel: %d", player.health, player.fuel);
            if (player.hasBullet)
                printf(" || BULLET READY");
            else
                printf(" || NO BULLET");

            printf("\nScore: %d", score);
            move++;
            deplete++;
            Sleep(10);
            if (player.fuel <= 0 || player.health == 0) {
                gameOver(player, enemies, &score, &game);
                system("cls");
                game = 0;
            }
        }
        return 0;
    }
}
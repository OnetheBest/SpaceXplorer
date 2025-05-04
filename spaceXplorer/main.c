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
    while (1) {
        srand(time(NULL));
        system("cls");

        //Variable setup
        int speed = 10;
        int move = 0;
        int pause = 0;
        int score = 0;
        int gameOverCondition = 0;

        //Call difficulty chooser
        Difficulty difficulty = titleScreen();
        Sleep(400);

        Player player = { {GRID_SIZE / 2, GRID_SIZE - 3}, 3, 100, 0 };
        Enemy enemies[MAX_ENEMIES] = {0};
        Collectible collectibles[MAX_COLLECTIBLES] = {0};
        Bullet bullet = {{-1, -1}, 0};

        applyDifficulty(&player, difficulty, &speed);
        spawnEnemies(enemies, MAX_ENEMIES);
        spawnCollectibles(collectibles, MAX_COLLECTIBLES);

        //Game loop
        while(!gameOverCondition) {
            system("cls");
            Controller(&player, &bullet);

            if (move % speed == 0) {
                if (!pause) {
                    Sleep(500);
                    pause = 1;
                }
                moveEnemies(enemies, MAX_ENEMIES, collectibles, MAX_COLLECTIBLES, &player);
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
            Sleep(10);

            if (player.fuel <= 0 || player.health <= 0) {
                gameOverCondition = 1;
            }
        }

        // === Game Over screen ===
        system("cls");
        printf("\n=== GAME OVER ===\n");
        printf("Your final score: %d\n", score);
        printf("Press 'R' to restart or any other key to quit...\n");

        char choice = getch();
        if (choice != 'r' && choice != 'R') {
            break;
        }
    }

    return 0;
}



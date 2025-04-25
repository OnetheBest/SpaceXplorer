#ifndef GAME_H
#define GAME_H

#include "entity.h"
#include <time.h>
#include <stdlib.h>




void drawGrid(Player player, Enemy enemies[], int enemyCount);
void spawnEnemies();
void moveEnemies(Enemy enemies[], int count);
void depleteFuel(Player *player);
void applyDifficulty(Player *player, Difficulty difficulty,int *speed);


#endif
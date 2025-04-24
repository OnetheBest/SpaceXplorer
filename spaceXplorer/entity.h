#ifndef ENTITY_H
#define ENTITY_H

#define GRID_SIZE 18
#define MAX_ENEMIES 15


typedef enum {
    EASY = 1,
    NORMAL,
    HARD,
    NIGHTMARE
} Difficulty;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int health;
    int fuel;
} Player;

typedef struct {
    Position pos;
    int spawned;
} Enemy;
#endif
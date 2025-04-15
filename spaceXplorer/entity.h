#ifndef ENTITY_H
#define ENTITY_h

#define GRID_SIZE 24

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int health;
    int fuel;
} Player;

#endif
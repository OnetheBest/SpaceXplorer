#include <conio.h>
#include <stdio.h>
#include "input.h"
#include "entity.h"

void Controller(Player *player){
    char inp;
    inp = _getch();
    switch (inp) {
        case 'w':
            if (player->pos.y > 0) player->pos.y -= 1;
            break;
        case 's':
            if (player->pos.y < GRID_SIZE - 1) player->pos.y += 1;
            break;
        case 'a':
            if (player->pos.x > 0) player->pos.x -= 1;
            break;
        case 'd':
            if (player->pos.x < GRID_SIZE - 1) player->pos.x += 1;
            break;
    }
}

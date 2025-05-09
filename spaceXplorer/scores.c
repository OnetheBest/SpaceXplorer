#include <stdio.h>
#include "scores.h"

void loadScores(int *highScore, int *lastScore) {
    FILE *file = fopen("scores.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", highScore);
        fscanf(file, "%d", lastScore);
        fclose(file);
    } else {
        *highScore = 0;
        *lastScore = 0;
    }
}

void saveScores(int score) {
    int highScore = 0, lastScore = score;
    FILE *file = fopen("scores.txt", "r");

    if (file != NULL) {
        fscanf(file, "%d", &highScore);
        fclose(file);
    }

    if (score > highScore) {
        highScore = score;
    }

    file = fopen("scores.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d\n%d\n", highScore, lastScore);
        fclose(file);
    }
}

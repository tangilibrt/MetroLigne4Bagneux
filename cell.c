#include "cell.h"
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>


t_d_cell *create_cell(int value, int levels) {

    t_d_cell *new_cell = (t_d_cell *)malloc(sizeof(t_d_cell));

    if (new_cell == NULL) {
        printf("t'a pas de memoire dans ton pc la hont");
        return NULL;
    }
    new_cell->levels = levels;
    new_cell->next = (t_d_cell **)malloc(levels * sizeof(t_d_cell *));

    if (new_cell->next == NULL) {
        free(new_cell);
        printf("t'a pas de memoire dans ton pc la hont");
        return NULL;
    }

    // Initialisation
    new_cell->value = value;
    for (int i = 0; i < levels; i++) {
        new_cell->next[i] = NULL;
    }

    return new_cell;
}
//
// Created by ilyes on 04/11/2023.
//
#ifndef PROJECT_DIARY_MANAGEMENT_CELL_H
#define PROJECT_DIARY_MANAGEMENT_CELL_H

#include <stdio.h>


typedef struct s_d_cell {
    int value;  // valeur de la cellule
    int levels; // nombre de niveau
    struct s_d_cell **next; // array de pointer
} t_d_cell;


t_d_cell *create_cell(int value, int levels);

#endif //PROJECT_DIARY_MANAGEMENT_CELL_H

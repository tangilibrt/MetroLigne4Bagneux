//
// Created by tangi on 25/10/2023.
//

#ifndef PROJET_C_MONOPOLY_H
#define PROJET_C_MONOPOLY_H


typedef struct s_multi_level_cell
{
    int value;
    struct s_multi_level_cell **next; // A dynamically allocated array of pointers
} t_multi_level_cell;

typedef struct s_multi_level_list
{
    t_multi_level_cell **heads; // A dynamically allocated array of head pointers
    int height; // The height of the multi-level list
} t_multi_level_list;




#endif //PROJET_C_MONOPOLY_H

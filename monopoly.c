//
// Created by tangi on 25/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "monopoly.h"



t_multi_level_cell createCell (int value, int height)
/*
 * Creates a cell with the given value and height.
 * The function takes value and height as parameters and returns a t_multi_level_cell.
 */
{
    t_multi_level_cell cell;
    cell.value = value;
    cell.next = (t_multi_level_cell **) malloc(sizeof(t_multi_level_cell *) * height);
    for (int i = 0; i < height; ++i)
    {
        cell.next[i] = NULL;
    }
    return cell;
}

t_multi_level_list createList (int height) {
    /*
     * Creates a multi-level list with the given height.
     * The function takes height as parameter and returns a t_multi_level_list.
     */
    t_multi_level_list list;
    list.height = height;
    list.heads = (t_multi_level_cell **) malloc(sizeof(t_multi_level_cell *) * height);
}

void insertCell (t_multi_level_list *list, t_multi_level_cell *cell) {

}
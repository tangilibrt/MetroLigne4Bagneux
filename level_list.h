

#ifndef PROJECT_DIARY_MANAGEMENT_LEVEL_LIST_H
#define PROJECT_DIARY_MANAGEMENT_LEVEL_LIST_H

typedef struct s_d_list {
    t_d_cell **heads;
    int max_levels;
} t_d_list;

t_d_list *create_mt_list(int max_levels);
/**
 * Create an empty list with max levels.
 * Takes as input the max number of levels.
 * Returns a pointer to the list.
 *
 * Example:
 * create_mt_list(3);
 * list->max_levels = 3;
 * list->heads = [NULL, NULL, NULL];
 */
t_d_list *create_mt_list_from_n(int n);
/**
 * Create a sorted level list with n levels and (2^n)-1 cells (the first cell is at index 1).
 * Takes as input the max number of levels.
 * Returns a pointer to the list.
 *
 * Example:
 * create_mt_list_from_n(3);
 * list->max_levels = 3;
 * align_and_display(list);
 * [list head_0]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-->NULL
 * [list head_1]--------->[ 2]--------->[ 4]--------->[ 6]-->NULL
 * [list head_2]----------------------->[ 4]---------------- >NULL
 */
void insert_cell_at_a_head(t_d_list *list, t_d_cell *cell);
/**
 * Insert a cell in a level list at all the levels from 0 to cell->levels (at the beginning of the list).
 * Takes as input the list and the cell to insert.
 * Modifies the list.
 * Returns nothing.
 *
 * Example:
 * insert_cell_at_a_head(list, cell);
 * allign_and_display(list);
 * [list head_0]-->[cell]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-->NULL
 * [list head_1]-->[cell]--------->[ 2]--------->[ 4]--------->[ 6]-->NULL
 * [list head_2]-->[cell]----------------------->[ 4]---------------- >NULL
 */
void insert_cell_at_a_particular_head(t_d_list *list, t_d_cell *cell, int level);
/**
 * Insert a cell in a level list at a particular level (keeps the list sorted).
 * Takes as input the list, the cell to insert, and the level.
 * Modifies the list.
 * Returns nothing.
 *
 * Example:
 * insert_cell_at_a_particular_head(list, cell, 1);
 * allign_and_display(list);
 * [list head_0]----------->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-->NULL
 * [list head_1]-->[cell]-->[ 1]-->[ 2]--------->[ 4]--------->[ 6]-->NULL
 */
void display_a_level(t_d_list *list, int level);
/**
 * Display a level of a level list.
 * Takes as input the list and the level to display.
 * Prints a particular level of the list.
 * Returns nothing.
 *
 * Example:
 * display_a_level(list, 0);
 * [list head_0]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-->NULL
 */
void display_all_levels(t_d_list *list);
/**
 * Display all the levels of a level list.
 * Takes as input the list.
 * Prints all the levels of the list.
 * Returns nothing.
 *
 * Example:
 * display_all_levels(list);
 * [list head_0]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-->NULL
 * [list head_1]-->[ 1]-->[ 2]-->[ 4]-->[ 6]-->NULL
 * [list head_2]-->[ 1]-->[ 4]-->[ 6]-->NULL
 */

void align_and_display(t_d_list *list);
/**
 * Align the levels of a level list and display it.
 * Takes as input the list.
 * Prints the list.
 * Returns nothing.
 *
 * Example:
 * align_and_display(list);
 * [list head_0]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-->NULL
 * [list head_1]-->[ 1]-->[ 2]--------->[ 4]--------->[ 6]-->NULL
 * [list head_2]-->[ 1]---------------->[ 4]----------[ 6]-->NULL
 */


void sorted_insert(t_d_list *list, t_d_cell *cell);
/**
 * OBSOLETE - NOT USED ANYMORE /!\ Insert a cell in a level list.
 * Takes as input the list and the cell to insert.
 * Insert the cell in the list.
 * Returns nothing.
 *
 * Example:
 * sorted_insert(list, cell);
 * [list head_0]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-->NULL
 * [list head_1]-->[ 1]-->[ 2]--------->[ 4]--------->[ 6]-->NULL
 * [list head_2]-->[ 1]---------------->[ 4]----------[ 6]-->NULL
 */

int classic_search(t_d_list *list, int value);
/**
 * Search a value in a level list in a classical way: starts at the head of the list and goes through it one by one.
 * Takes as input the list and the value to search.
 * Returns the number of operations made to find the value.
 * Returns -1 if the value is not found.
 *
 * Example:
 * classic_search(list, 4);
 * 4
 * classic_search(list, 10);
 * -1
 */

int optimized_search(t_d_list *list, int value);
/**
 * Search through a level list in an optimized way (sort of dichotomic search).
 * Starts on the last level which only contains the middle value of the list.
 * If the value is greater than the middle value, we go down one level and we start from the previous cell.
 * If the value is less than the middle value, we go down one level and we start from the previous cell.
 * As the level below contains the values at the middle between the previous middle and the start/end of the list,
 * we can go down one level and start from the previous cell.
 * We repeat this process until we find the value or we reach the last level.
 * Takes as input the list and the value to search.
 * Returns the number of operations made to find the value.
 * Returns -1 if the value is not found.
 *
 * Example:
 * list = create_list(3);
 * align_and_display(list);
 * optimized_search(list, 5);
 * 3
 */

int research_time(t_d_list *list, int nbr_of_research, int n);
/**
 * Function that measures the time taken to search an n number of random values in a list in a classic way and in an optimized way.
 * Takes as input the list, the number of research to do, and the height of the list.
 * Prints the time taken to do the research in both ways.
 * Returns nothing.
 *
 * Example:
 * list = create_list(10);
 * research_time(list, 100000, 10);
 * CPU time used for classic search: 0.191000
 * CPU time used for optimized search: 0.020000
 */

#endif //PROJECT_DIARY_MANAGEMENT_LEVEL_LIST_H
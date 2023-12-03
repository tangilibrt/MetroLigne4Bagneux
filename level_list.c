#include "cell.h"
#include "level_list.h"
#include <stdlib.h>
#include <math.h>


t_d_list *create_mt_list(int max){

    t_d_list *list = (t_d_list *)malloc(sizeof(t_d_list));
    list->heads = (t_d_cell **)calloc(max, sizeof(t_d_cell *));
    list->max_levels = max ;
}

t_d_list *create_mt_list_from_n(int n) {
    t_d_list *list = (t_d_list *)malloc(sizeof(t_d_list));
    list->heads = (t_d_cell **)calloc(n, sizeof(t_d_cell *));
    list->max_levels = n;
    int twoN = (int)pow(2, n);
    int count = 2; // will go from 0 to count

    for (int current_level = n; current_level > 0; current_level--) {
        for (int index = 1; index < (int)(pow(2, n) - 1); index++) {
            for (int i = 1; i < count; i++) {
                // the point here is to check if any number between 1 and count divided by
                // count is equal to the total number of cells hence checking if we can insert a cell at this index
                double calculated_index = (i * twoN) / (double) count;
                // Check if the calculated index is approximately equal to the desired index (because of the double)
                if (fabs(calculated_index - index) < 0.0001) {
                    t_d_cell *cell = create_cell(index, current_level);
                    insert_cell_at_a_particular_head(list, cell, current_level - 1);
                }
            }

        }

        count *= 2;
    }

    align_and_display(list);
    return list;
}

void insert_cell_at_a_head(t_d_list *list, t_d_cell *cell){
    for (int i = 0; i < cell->levels; i++) {
        cell->next[i] = list->heads[i];
        list->heads[i] = cell;}

}

void insert_cell_at_a_particular_head(t_d_list *list, t_d_cell *cell, int level) {
    t_d_cell *current = list->heads[level];
    t_d_cell *prev = NULL;

    while (current != NULL && current->value < cell->value) {
        prev = current;
        current = current->next[level];
    }

    if (prev == NULL) {
        // Insert at the beginning of the list
        cell->next[level] = list->heads[level];
        list->heads[level] = cell;
    } else {
        // Insert in the middle or at the end of the list
        cell->next[level] = current;
        prev->next[level] = cell;
    }
}


void display_a_level(t_d_list *list, int level){
    if (level < 0 || level >= list->max_levels) {
        printf("Invalid level\n");
        return;
    }
    printf("[list head_%d]--", level);

    t_d_cell *cell_actuel = list->heads[level];

    while (cell_actuel != NULL ) {
        printf(">[ %d]--", cell_actuel->value);
        cell_actuel = cell_actuel->next[level];
    }
    printf(" >NULL\n");
}

void display_all_levels(t_d_list *list){
    for (int i = 0; i< list->max_levels; i++)
    {
        display_a_level( list, i);
    }
}


void align_and_display(t_d_list *list) {
    // Afficher le niveau 0
    printf("[list head_%d]--", 0);
    t_d_cell *current = list->heads[0];
    while (current != NULL) {
        printf(">[ %d]--", current->value);
        current = current->next[0];
    }
    printf(" >NULL\n");

    // Afficher les niveaux supérieurs
    for (int i = 1; i < list->max_levels; i++) {
        printf("[list head_%d]--", i);
        t_d_cell *current_level = list->heads[i];
        t_d_cell *current_base = list->heads[0];

        while (current_base != NULL) {
            if (current_level != NULL && current_base->value == current_level->value) {
                printf(">[ %d]--", current_level->value);
                current_level = current_level->next[i];
            } else {
                printf("-------");
            }
            current_base = current_base->next[0];
        }
        printf(" >NULL\n");
    }
}

void sorted_insert(t_d_list *list, t_d_cell *cell) {
    for (int i = 0; i < cell->levels; i++) {
        t_d_cell **temp = &(list->heads[i]);
        while (*temp && (*temp)->value < cell->value) {
            temp = &((*temp)->next[i]);
        }
        cell->next[i] = *temp;
        *temp = cell;
    }
}



int classic_search(t_d_list *list, int value) {
    t_d_cell *current = list->heads[0];
    int complexity_counter = 0;
    while (current != NULL) {
        complexity_counter++;
        if (current->value == value) {
            return complexity_counter; // Found
        }
        current = current->next[0];
    }
    return -1; // Not found
}

int optimized_searh(t_d_list *list, int value) {
    int level = list->max_levels - 1;
    printf( "valeur head 0 etc (%d,%d,%d,%d,%d,%d,%d,%d,%d,%d)\n",list->heads[0]->value,list->heads[1]->value,list->heads[2]->value,list->heads[3]->value,list->heads[4]->value,list->heads[5]->value,list->heads[6]->value,list->heads[7]->value,list->heads[8]->value,list->heads[9]->value);
    while(list->heads[level] == NULL){level--;}
    t_d_cell *current = list->heads[level];
    printf("level%d, valu%d\n", current->levels, current->value);
    while (level >= 0) {
        while (current != NULL && current->value < value) {
            current = current->next[level];
            printf("level%d, valu%d\n", current->levels, current->value);
        }
        if (current != NULL && current->value == value) {
            printf("trouver au niveau %d\n",level);
            return 1; // Found
        }
        level--;
        if (level >= 0 && current != NULL) {
            current = list->heads[level];
            printf("level%d, valu%d\n", current->levels, current->value);
        }
    }
    return 0; // Not found
}
int optimized_search(t_d_list *list, int value){
    int level = list->max_levels -1 ;
    int complexity_counter = 0 ;
    while(list->heads[level] == NULL){
        level--;
    }
    t_d_cell *current = list->heads[level];
    t_d_cell *prev = list->heads[level] ;

    while (level >= 0) {
        complexity_counter++;

        if (current != NULL) {

            if (current->value == value) {
                printf("found after %d steps at level %d\n", complexity_counter, level);
                return complexity_counter;
            } else if (current->value < value) {
                prev = current;
                current = current->next[level];

            } else { // current->value > value, the value we're looking for is less than the current value which means it's not in this level we need to go down
                level--;
                if (prev == list->heads[level+1]) {
                    prev = list->heads[level];
                }
                current = prev; // we go down one level and we start from the previous cell
            }
        } else {
            level--;
            if (prev == list->heads[level+1]) {
                prev = list->heads[level];
            }
            current = prev;
        }
    }
    return -1 ;

}

void free_level(t_d_cell *head) {
    while (head) {
        t_d_cell *temp = head;
        head = head->next[0];
        free(temp->next);
        free(temp);
    }
}


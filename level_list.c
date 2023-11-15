#include "cell.h"
#include "level_list.h"
#include <stdlib.h>


t_d_list *create_mt_list(int max){

    t_d_list *list = (t_d_list *)malloc(sizeof(t_d_list));
    list->heads = (t_d_cell **)calloc(max, sizeof(t_d_cell *));
    list->max_levels = max ;
}

void insert_cell_at_a_head(t_d_list *list, t_d_cell *cell){
    for (int i = 0; i < cell->levels; i++) {
        cell->next[i] = list->heads[i];
        list->heads[i] = cell;}

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

int look_for_value(t_d_list *list, int level ,int value ){

    t_d_cell *current = list->heads[level-1];
    while (current != NULL) {
        //printf("current = %d , previouse : %d", current->value , value );
        if (current->value == value) {
            return 1; // La valeur a été trouvée
        }
        current = current->next[level];
    }
    return 0 ;
}

void align_and_display(t_d_list *list){

    printf("[list head_%d]--", 0);

    t_d_cell *cell_actuel = list->heads[0];

    while (cell_actuel != NULL ) {
        printf(">[ %d]--", cell_actuel->value);
        cell_actuel = cell_actuel->next[0];
    }
    printf(" >NULL\n");

    for (int i = 1; i< list->max_levels; i++){
        printf("[list head_%d]--", i);

        t_d_cell *cell_actuel = list->heads[i];
        int y = 0 ;
        while (cell_actuel != NULL ) {
            int exist = look_for_value(list, i, cell_actuel->value);

            if (exist == 1) {
                printf(">[ %d]--", cell_actuel->value);
            } else if (exist == 0) {
                printf("-------" );
            }
            y++;
            cell_actuel = cell_actuel->next[y];

        }
        printf(" >NULL\n");
    }
}



void sorted_insert(t_d_list *list, t_d_cell *cell){


}





void free_level(t_d_cell *head) {
    while (head) {
        t_d_cell *temp = head;
        head = head->next[0];
        free(temp->next);
        free(temp);
    }
}


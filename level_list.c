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

    // Tableau de pointeurs pour garder une trace des points d'insertion à chaque niveau
    t_d_cell *update[list->max_levels];
    for (int i = 0; i < list->max_levels; i++) {
        update[i] = NULL;
    }

    // Parcourir la liste à partir du niveau le plus élevé
    for (int level = list->max_levels - 1; level >= 0; level--) {
        t_d_cell *current = list->heads[level];
        while (current != NULL && current->value > cell->value) {
            // Continuer à avancer dans la liste
            update[level] = current;
            current = current->next[level];
        }

        // Si la cellule a un niveau suffisant, la mettre à jour pour l'insertion
        if (level < cell->levels) {
            if (update[level] == NULL) {
                // Insertion en tête de liste à ce niveau
                cell->next[level] = list->heads[level];
                list->heads[level] = cell;
            } else {
                // Insertion au milieu ou à la fin de la liste à ce niveau
                cell->next[level] = update[level]->next[level];
                update[level]->next[level] = cell;
            }
        }
    }
}




void free_level(t_d_cell *head) {
    while (head) {
        t_d_cell *temp = head;
        head = head->next[0];
        free(temp->next);
        free(temp);
    }
}


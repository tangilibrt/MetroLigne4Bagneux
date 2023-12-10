#include "cell.h"
#include "level_list.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>


t_d_list *create_mt_list(int max){
    t_d_list *list = (t_d_list *)malloc(sizeof(t_d_list));
    list->heads = (t_d_cell **)calloc(max, sizeof(t_d_cell *));
    list->max_levels = max ;
    return list;
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

int research_time(t_d_list *list, int nbr_of_research, int n) {
    srand(time(NULL));
    clock_t start_time_classic, end_time_classic, start_time_optimized, end_time_optimized;
    double cpu_time_used_classic, cpu_time_used_optimized;

    start_time_classic = clock();
    for (int i= 0; i < nbr_of_research; i++) {
        // Générer une valeur aléatoire entre 0 et 2^N-1 pour chercher nbr_of_research fois une valeur aleatoire dans la liste
        int value = rand() % (int)pow(2, n)-1;
        int complexity_classic = classic_search(list, value);
    }
    end_time_classic = clock();
    cpu_time_used_classic = ((double) (end_time_classic - start_time_classic)) / CLOCKS_PER_SEC;
    printf("CPU time used for classic search: %f\n", cpu_time_used_classic);

    start_time_optimized = clock();
    for (int i= 0; i < nbr_of_research; i++) {
        // Générer une valeur aléatoire entre 0 et 2^N-1 pour chercher 100x une valeur aleatoire dans la liste
        int value = rand() % (int)pow(2, n)-1;
        int complexity_optimized = optimized_search(list, value);
    }
    end_time_optimized = clock();
    cpu_time_used_optimized = ((double) (end_time_optimized - start_time_optimized)) / CLOCKS_PER_SEC;
    printf("CPU time used for optimized search: %f\n", cpu_time_used_optimized);
    return 0;
}

void free_level(t_d_cell *head) {
    while (head) {
        t_d_cell *temp = head;
        head = head->next[0];
        free(temp->next);
        free(temp);
    }
}

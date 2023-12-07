#include "cell.h"
#include "level_list.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>


t_d_list *create_mt_list(int max){
    """Create an empty list with max levels"
    "takes as input the max number of levels"
    "returns a pointer to the list"

    "example:"
    ">>> create_mt_list(3)"
    ">>> list->max_levels = 3"
    ">>> list->heads = [NULL, NULL, NULL]";

    t_d_list *list = (t_d_list *)malloc(sizeof(t_d_list));
    list->heads = (t_d_cell **)calloc(max, sizeof(t_d_cell *));
    list->max_levels = max ;
    return list;
}

t_d_list *create_mt_list_from_n(int n) {
    """Create a sorted level list with n levels and (2^n)-1 cells (the first cell is at index 1)"
    "takes as input the max number of levels"
    "returns a pointer to the list"

    "example:"
    ">>> create_mt_list_from_n(3)"
    ">>> list->max_levels = 3"
    ">>> allign_and_display(list)"
    ">>> [list head_0]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-- >NULL\n"
    "    [list head_1]--------->[ 2]--------->[ 4]--------->[ 6]-- >NULL\n"
    "    [list head_2]----------------------->[ 4]---------------- >NULL";

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
    """Insert a cell in a level list at all the levels from 0 to cell->levels (at the beginning of the list)"
    "takes as input the list and the cell to insert"
    "modifies the list"
    "returns nothing"

    "example:"
    ">>> insert_cell_at_a_head(list, cell)"
    ">>> allign_and_display(list)"
    ">>> [list head_0]-->[cell]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-- >NULL\n"
    "    [list head_1]-->[cell]--------->[ 2]--------->[ 4]--------->[ 6]-- >NULL\n";
    "    [list head_2]-->[cell]----------------------->[ 4]---------------- >NULL";

    for (int i = 0; i < cell->levels; i++) {
        cell->next[i] = list->heads[i];
        list->heads[i] = cell;}

}

void insert_cell_at_a_particular_head(t_d_list *list, t_d_cell *cell, int level) {
    """Insert a cell in a level list at a particular level (keeps the list sorted)"
    "takes as input the list, the cell to insert and the level"
    "modifies the list"
    "returns nothing"

    "example:"
    ">>> insert_cell_at_a_particular_head(list, cell, 1)"
    ">>> allign_and_display(list)"
    ">>> [list head_0]----------->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-- >NULL\n"
    "    [list head_1]-->[cell]-->[ 1]-->[ 2]--------->[ 4]--------->[ 6]-- >NULL\n";

    "As seen here, should not be used alone, but in a function like create_mt_list_from_n()";
    "The point of this function is to insert at a deeper level than 0 and be able to jump some indexes";

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
    """Display a level of a level list"
    "takes as input the list and the level to display"
    "prints a particular level of the list"
    "returns nothing"

    "example:"
    ">>> display_a_level(list, 0)"
    ">>> [list head_0]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-- >NULL\n";
    "";
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
    """Display all the levels of a level list"
    "takes as input the list"
    "prints all the levels of the list"
    "returns nothing"

    "example:"
    ">>> display_all_levels(list)"
    ">>> [list head_0]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-- >NULL\n";
    "    [list head_1]-->[ 1]-->[ 2]-->[ 4]-->[ 6]-- >NULL\n";
    "    [list head_2]-->[ 1]-->[ 4]-->[ 6]-- >NULL\n";


    for (int i = 0; i< list->max_levels; i++)
    {
        display_a_level( list, i);
    }
}


void align_and_display(t_d_list *list) {
    """Align the levels of a level list and display it"
    "takes as input the list"
    "prints the list"
    "returns nothing"

    "example:"
    ">>> align_and_display(list)"
    ">>> [list head_0]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-- >NULL\n";
    "    [list head_1]-->[ 1]-->[ 2]--------->[ 4]--------->[ 6]-- >NULL\n";
    "    [list head_2]-->[ 1]---------------->[ 4]----------[ 6]-- >NULL\n";

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
    """OBSOLETE - NOT USED ANYMORE /!\""

    """Insert a cell in a level list"
    "takes as input the list and the cell to insert"
    "insert the cell in the list"
    "returns nothing"

    "example:"
    ">>> sorted_insert(list, cell)"
    ">>> [list head_0]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-- >NULL\n";
    "    [list head_1]-->[ 1]-->[ 2]--------->[ 4]--------->[ 6]-- >NULL\n";
    "    [list head_2]-->[ 1]---------------->[ 4]----------[ 6]-- >NULL\n";

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
    """Search a value in a level list in a classical way : starts at the head of the list and goes through it one by one"
    "takes as input the list and the value to search"
    "returns the number of operations made to find the value";
    "returns -1 if the value is not found"

    "example:"
    ">>> classic_search(list, 4)"
    ">>> 4";
    ">>> classic_search(list, 10)"
    ">>> -1";
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
    """Search through a level list in an optimized way (sort of dichotomic search) : "
      "Starts on the last level which only contains the middle value of the list"
        "If the value is greater than the middle value, we go down one level and we start from the previous cell"
        "If the value is less than the middle value, we go down one level and we start from the previous cell"
        "As the level below contains the values at the middle between the previous middle and the start/end of the list, we can go down one level and start from the previous cell"
        "We repeat this process until we find the value or we reach the last level"
    "takes as input the list and the value to search"
    "returns the number of operations made to find the value";
    "returns -1 if the value is not found"

    "example:"
    ">>> list = create_list(3)"
    ">>> align_and_display(list)"
    ">>> [list head_0]-->[ 1]-->[ 2]-->[ 3]-->[ 4]-->[ 5]-->[ 6]-- >NULL"
        "[list head_1]--------->[ 2]--------->[ 4]--------->[ 6]-- >NULL"
        "[list head_2]----------------------->[ 4]---------------- >NULL"
    ">>> optimized_search(list, 5)"
    ">>> 3";

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
    """Function that measures the time taken to search an n number of random values in a list in a classic way and in an"
      " optimized way"
    "takes as input the list, the number of research to do and the height of the list"
    "prints the time taken to do the research in both ways"
    "returns nothing"

    "example:"
    ">>> list = create_list(10)"
    ">>> research_time(list, 100000, 10)";
    ">>> CPU time used for classic search: 0.191000\n"
    ">>> CPU time used for optimized search: 0.020000";




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


#include "cell.h"
#include "level_list.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>

int main() {
    int max_levels = 10;

    // Initialiser le générateur de nombres aléatoires
    srand((unsigned int)time(NULL));

    // Créer une liste multi-niveaux vide
    t_d_list *list_test = create_mt_list(max_levels);

    printf("Empty level list:\n");
    display_all_levels(list_test);


    for (int value = 11; value > 0 ; value--) {
        int cell_levels = rand() % max_levels + 1; // 1 à max_levels
        t_d_cell *new_cell = create_cell(value, cell_levels);
        if (!new_cell) {
            printf("Failed to create a cell with value %d.\n", value);
        } else {
            insert_cell_at_a_head(list_test, new_cell);
        }
    }


    // Afficher la liste après les insertions
    printf("\nList after inserting cells:\n");
    align_and_display(list_test);
    printf("\n\n\n\n\n");


    printf("\nList after inserting cells:\n");
    align_and_display(list_test);
    printf("\n\n\n\n\n");

    int search_value = 6;
    printf("Classic search for %d: %s\n", search_value, classic_search(list_test, search_value) ? "Found" : "Not Found");
    printf("Optimized search for %d: %s\n", search_value, optimized_search(list_test, search_value) ? "Found" : "Not Found");


    return 0;
}

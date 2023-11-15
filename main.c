#include "cell.h"
#include "level_list.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>

int main() {
    int max_levels = 5;

    // Initialiser le générateur de nombres aléatoires
    srand((unsigned int)time(NULL));

    // Créer une liste multi-niveaux vide
    t_d_list *list_test = create_mt_list(max_levels);

    printf("Empty level list:\n");
    display_all_levels(list_test);

    // Insérer une cellule avec la valeur 1 à tous les niveaux
    t_d_cell *cell_1 = create_cell(1, max_levels);
    if (!cell_1) {
        printf("Failed to create a cell with value 1.\n");
    } else {
        insert_cell_at_a_head(list_test, cell_1);
    }

    // Insérer des cellules avec des valeurs aléatoires entre 2 et 3
    // et avec un nombre aléatoire de niveaux pour chaque cellule
    for (int value = 2; value < 3; value++) {
        int cell_levels = rand() % max_levels + 1; // 1 à max_levels
        t_d_cell *new_cell = create_cell(value, cell_levels);
        if (!new_cell) {
            printf("Failed to create a cell with value %d.\n", value);
        } else {
            insert_cell_at_a_head(list_test, new_cell);
        }
    }

    // Insérer une cellule avec la valeur 3 à tous les niveaux
    t_d_cell *cell_3 = create_cell(3, max_levels);
    if (!cell_3) {
        printf("Failed to create a cell with value 3.\n");
    } else {
        insert_cell_at_a_head(list_test, cell_3);
    }

    // Afficher la liste après les insertions
    printf("\nList after inserting cells:\n");
    align_and_display(list_test);
    printf("\n\n\n\n\n");
    display_all_levels(list_test);



    return 0;
}

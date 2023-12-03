//
// Created by tangi on 03/12/2023.
//

#include "diary.h"

diary *create_diary() {
    diary *new_diary = (diary *) malloc(sizeof(diary));
    if (new_diary == NULL) {
        printf("t'a pas de memoire dans ton pc la honte");
        return NULL;
    }
    new_diary->list_entries = (entry **) malloc(4 * sizeof(entry *));
    if (new_diary->list_entries == NULL) {
        free(new_diary);
        printf("t'a pas de memoire dans ton pc la honte");
        return NULL;
    }
    for (int i = 0; i < 4; i++) {
        new_diary->list_entries[i] = NULL;
    }
    return new_diary;
}

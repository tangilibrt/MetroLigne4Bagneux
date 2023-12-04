//
// Created by tangi on 03/12/2023.
//

#include "diary.h"
#include "string.h"

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

entry *create_entry(char *name, char *surname) {
    entry *new_entry = (entry *) malloc(sizeof(entry));
    if (new_entry == NULL) {
        printf("t'a pas de memoire dans ton pc la honte");
        return NULL;
    }
    new_entry->contact = (p_contact) malloc(sizeof(p_contact));
    if (new_entry->contact == NULL) {
        free(new_entry);
        printf("t'a pas de memoire dans ton pc la honte");
        return NULL;
    }
    new_entry->contact->name = name;
    new_entry->contact->surname = surname;
    new_entry->list_appointments = NULL;
    new_entry->next = (entry **) malloc(4 * sizeof(entry *));
    if (new_entry->next == NULL) {
        free(new_entry);
        printf("t'a pas de memoire dans ton pc la honte");
        return NULL;
    }
    for (int i = 0; i < 4; i++) {
        new_entry->next[i] = NULL;
    }
    return new_entry;
}

void add_entry(diary *diary, entry *entry) {
    // if the diary is empty we add the entry at all the levels
    if (diary->list_entries[0] == NULL) {
        for (int i = 0; i < 4; i++) {
            diary->list_entries[i] = entry;
        }
    }
    // we look through all the entries at the last level to see if the diary is not empty and another entry has the same first letter of surname only we add the entry at all the levels except the last one
    else {
        struct entry **current_entry;
        current_entry = diary->list_entries;
        while (current_entry[3] != NULL && current_entry[3]->next[3] != NULL) {
                if (current_entry[3]->contact->surname[0] == entry->contact->surname[0]) {
                    while (current_entry[2]->next[2] != NULL) {
                        if (current_entry[2]->contact->surname[1] == entry->contact->surname[1]) {
                            while (current_entry[1]->next[1] != NULL) {
                                if (current_entry[1]->contact->surname[2] == entry->contact->surname[2]) {
                                    while (current_entry[0]->next[0] != NULL) {
                                        current_entry[0] = current_entry[0]->next[0];
                                    }
                                    current_entry[0]->next[0] = entry;
                                    printf("entry %s added at level %d of %s\n", entry->contact->surname, 0, current_entry[0]->contact->surname);
                                    printf("next of %s is %s\n", current_entry[0]->contact->surname, current_entry[0]->next[0]->contact->surname);
                                    return;
                                }
                                current_entry[1] = current_entry[1]->next[0];
                            }
                            current_entry[1]->next[1] = entry;
                            printf("entry %s added at level %d of %s\n", entry->contact->surname, 1, current_entry[1]->contact->surname);
                            return;
                        }
                        current_entry[2] = current_entry[2]->next[0];
                    }
                    current_entry[2]->next[2] = entry;
                    printf("entry %s added at level %d of %s\n", entry->contact->surname, 2, current_entry[2]->contact->surname);
                    return;
                }
                current_entry[3] = current_entry[3]->next[0];
            }
            if (current_entry[3]!=NULL)
                current_entry[3]->next[3] = entry;
            else
                diary->list_entries[3] = entry;
                diary->list_entries[2] = entry;
                diary->list_entries[1] = entry;
            printf("entry %s added at level %d of %s\n", entry->contact->surname, 3, current_entry[3]->contact->surname);
            return;}
    }

void align_and_display_diary(diary *diary) {
    // Afficher le niveau 0
    printf("[list head_%d]--", 0);
    entry *current = diary->list_entries[0];
    while (current != NULL) {
        printf(">[ %s]--", current->contact->surname);
        current = current->next[0];
    }
    printf(" >NULL\n");

    // Afficher les niveaux supérieurs
    for (int i = 1; i < 4; i++) {
        printf("[list head_%d]--", i);
        entry *current_level = diary->list_entries[i];
        entry *current_base = diary->list_entries[0];

        while (current_base != NULL) {
            if (current_level != NULL) {
                printf(">[ %s]--", current_level->contact->surname);
                current_level = current_level->next[i];
            } else {
                printf("-------");
            }
            current_base = current_base->next[0];
        }
        printf(" >NULL\n");
    }
}
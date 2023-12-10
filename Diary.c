#include "Diary.h"


t_d_diary *create_mt_diary(int max){

    t_d_diary *diary = (t_d_diary *)malloc(sizeof(t_d_diary));
    diary->heads = (t_d_contact **)calloc(max, sizeof(t_d_contact *));
    diary->max_levels = max ;
    return diary;
}

void insert_contact(t_d_diary *diary, t_d_contact *contact) {
    if (diary->heads[1]==NULL) {
        printf("the diary is empty\n");
        for (int level = 1; level <= 4 ; level++) {
            diary->heads[level] = (t_d_contact *)malloc(sizeof(t_d_contact));
            diary->heads[level]->next = NULL;
            diary->heads[level]->surname = NULL;
            diary->heads[level]->firstname = NULL;

            memcpy(diary->heads[level], contact, sizeof(t_d_contact));
        }
    } else {
        printf("the diary is not empty\n");
        t_d_contact **holder = (t_d_contact **)malloc(sizeof(t_d_contact *));
        t_d_contact **highestPrevious = (t_d_contact **)malloc(sizeof(t_d_contact *));
        t_d_contact **memory = diary->heads;
        highestPrevious = diary->heads;

        int foundPlace = 0;
        int level = 4;
        while (memory[level]->next != NULL && level > 0) {
            printf("entered the while loop at level %d\n", level);
            holder[level]->next[level] = memory[level]->next[level];
            if (memory[level]->next[level]->surname[4-level] == contact->surname[4-level] && foundPlace == 0) {
                printf("entered the if == statement at level %d\n", level);
                if (strcmp(memory[level]->next[level]->surname, contact->surname) == 0) {
                    contact->next[level] = memory[level]->next[level];
                    memory[level]->next[level] = contact;
                }

                level--;
                if (level == 1) {
                    foundPlace = 1;
                    contact->next[level] = memory[level]->next[level];
                    memory[level]->next[level] = contact;

                }
            }
            if (strcmp(memory[level]->next[level]->surname, contact->surname) == 0 && foundPlace == 1)
            {
                printf("entered the if strcmp & fP==1 statement at level %d\n", level);
                contact->next[level] = memory[level]->next[level];
                memory[level]->next[level] = contact;
                level--;
                memory[level] = highestPrevious[level];
            }
            else if (memory[level]->next[level]->surname[4-level] > contact->surname[4-level]) {
                printf("entered the if > statement at level %d\n", level);
                contact->next[level] = memory[level]->next[level];
                memory[level]->next[level] = contact;
                foundPlace = 1;
                for (int i = 1; i <= level; i++) {
                    highestPrevious[i] = memory[level];
                }
                level--;
            }

            else if (memory[level]->next[level]->surname[4-level] < contact->surname[4-level]){
                printf("entered the if < statement at level %d\n", level);
                memory[level] = memory[level]->next[level];
            }

        }
        if (memory[level]->next[level] == NULL) {
            printf("entered the if == NULL statement at level %d\n", level);
            memory[level]->next[level] = contact;
            level--;
        }
        free(contact);
        free(holder);
        free(highestPrevious);
    }

}

void display_a_level_names(t_d_diary *diary, int level){
    if (level < 0 || level >= diary->max_levels) {
        printf("Invalid level\n");
        return;
    }
    printf("[diary head_%d]--", level);

    t_d_contact *contact_current = diary->heads[level];

    while (contact_current != NULL ) {
        printf(">[ %s]--", contact_current->surname);
        contact_current = contact_current->next[level];
    }
    printf(" >NULL\n");
}

void display_all_levels_names(t_d_diary *diary){
    for (int level = 1; level <= diary->max_levels; level++) {
        display_a_level_names(diary, level);
    }
}

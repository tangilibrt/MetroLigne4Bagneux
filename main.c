#include "cell.h"
#include "level_list.h"
#include "Diary.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include "contact.h"
#include <string.h>
#include "unistd.h"
#include "math.h"
int main() {

// menu
    printf("              /~___________~\\ \n"
                 "              .-------------. \n"
                 "             (|Diary Project|)\n"
                 "              '-------------' \n"
                 "              \\_~~~~~~~~~~~_/\n\n");
    int choix = 0;
    int continuer = 1;
    t_d_diary *diary = create_mt_diary(4);
    while (continuer == 1) {
        printf("+-------------------------------------------+\n");
        printf("|                Main Menu                  |\n");
        printf("+-------------------------------------------+\n");
        printf("| 1. Part 1 and 2                           |\n");
        printf("| 2. Part 3                                 |\n");
        printf("| 3. Exit                                   |\n");
        printf("+-------------------------------------------+\n");
        printf("| Enter your choice:                        |\n");
        printf("+-------------------------------------------+\n");
        scanf("%d", &choix);
        if (choix == 1) {
            printf("+----------------------------------------------+\n");
            printf("|               Part 1 & 2                     |\n");
            printf("+----------------------------------------------+\n");
            printf("| 1. Create a list from a given depth          |\n");
            printf("| 2. Search through a list of n depth classic  |\n");
            printf("| 3. Search through a list of n depth optimized|\n");
            printf("| 4. Compare time taken to do n researches(C&O)|\n");
            printf("| 5. Exit                                      |\n");
            printf("+----------------------------------------------+\n");
            printf("| Enter your choice:                           |\n");
            printf("+----------------------------------------------+\n");
            scanf("%d", &choix);
            if (choix == 1) {
                printf("Enter the depth of the list you want to create, it sould be 10 or below otherwise the"
                       " list will be too big to handle :\n");
                int depth;
                scanf("%d", &depth);
                if (depth > 10) {
                    printf("The depth is too big, the list will be too big to handle\n");;
                } else {
                    align_and_display(create_mt_list_from_n(depth));
                }
            }
            if (choix == 2) {
                printf("Enter the depth of the list you want to create, it sould be 10 or below otherwise the"
                       " list will be too big to handle :\n");
                int depth;
                scanf("%d", &depth);
                if (depth > 10) {
                    printf("The depth is too big, the list will be too big to handle\n");;
                } else {
                    t_d_list *list = create_mt_list_from_n(depth);
                    printf("Enter the value you want to search\n");
                    int value;
                    scanf("%d", &value);
                    if (value > pow(2, depth)) {
                        printf("the value is not in the list, it should be below %d\n", pow(2, depth));
                    } else {
                        printf("The value %d is at the level %d\n", value, classic_search(list, value));
                    }
                }
            }
            if (choix == 3) {
                printf("Enter the depth of the list you want to create, it sould be 10 or below otherwise the"
                       " list will be too big to handle :\n");
                int depth;
                scanf("%d", &depth);
                t_d_list *list = create_mt_list_from_n(depth);
                printf("Enter the value you want to search\n");
                int value;
                scanf("%d", &value);
                printf("The value %d has been found in %d steps\n", value, optimized_search(list, value));
            }
            if (choix == 4) {
                printf("Enter the depth of the list you want to create\n");
                int depth;
                scanf("%d", &depth);
                if (depth > 10) {
                    printf("The depth is too big, the list will be too big to handle\n");;
                } else {
                    t_d_list *list = create_mt_list_from_n(depth);
                    printf("Enter the number of researches you want to do\n");
                    int nbr_of_research;
                    scanf("%d", &nbr_of_research);
                    if (nbr_of_research > pow(2, depth)) {
                        printf("the value is not in the list, it should be below %d\n", pow(2, depth));
                    } else {
                        printf("Enter the value you want to search\n");
                        int value;
                        scanf("%d", &value);
                        research_time(list, nbr_of_research, value);
                    }
                }
            }
        }
        if (choix == 2) {
            printf("+----------------------------------------------+\n");
            printf("|               Part 3                         |\n");
            printf("+----------------------------------------------+\n");
            printf("| 1. Create a contact                          |\n");
            printf("| 2. Create appointment                        |\n");
            printf("| 3. Display all appointments of a contact     |\n");
            printf("| 4. Create diary                              |\n");
            printf("| 5. Display diary                             |\n");
            printf("| 6. Insert contact at a head of diary         |\n");
            printf("| 7. Exit                                      |\n");
            printf("+----------------------------------------------+\n");
            printf("| Enter your choice:                           |\n");
            printf("+----------------------------------------------+\n");
            scanf("%d", &choix);
            if (choix == 1) {
                t_d_contact *contact = create_contact();
                printf("The contact %s has been created\n", strcat(strcat(contact->surname," "),contact->firstname));
                free(contact);
                sleep(1);
            }
            if (choix == 2) {
                appointment *appointment = creat_apointem();
                printf("The appointment %s has been created\n", appointment->purpose);
                free(appointment);
                sleep(1);
            }
            if (choix == 3) {
                printf("Enter the name of the contact you want to display\n");
                char name[50];
                scanf("%s", name);
                t_d_contact *temp = create_contact();
                while (temp != NULL && strcmp(temp->surname, name) != 0) {
                    temp = temp->next[0];
                }
                if (temp == NULL) {
                    printf("The contact %s does not exist\n", name);
                } else {
                    view_apo(temp);
                    sleep(1);
                }
                free(temp);
                sleep(1);
            }
            if (choix == 4) {
                diary = create_mt_diary(4);
                printf("The diary has been created\n");
                sleep(1);
            }
            if (choix == 5) {
                display_all_levels_names(diary);
                sleep(1);
            }
            if (choix == 6) {
                printf("Enter the name of the contact you want to insert\n");
                char name[50];
                scanf("%s", name);
                t_d_contact *contact = create_contact();
                insert_contact(diary, contact);
                printf("The contact %s has been inserted\n", strcat(strcat(contact->surname," "),contact->firstname));
                sleep(1);
            }
            if (choix == 7) {
                continuer = 0;
            }
            else {
                printf("Wrong choice\n");
                sleep(1);
            }
        }
        if (choix == 3) {
            continuer = 0;
        }
        else {
            printf("Wrong choice\n");
            sleep(1);
        }

    }
    return 0;
}

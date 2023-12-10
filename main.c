#include "cell.h"
#include "level_list.h"
#include "Diary.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include "contact.h"
int main() {
    t_d_diary *test = create_mt_diary(4);
    display_all_levels_diary(test);


    t_d_contact *contact_test1 = create_contact();
    insert_cell_at_a_head_diary(test, contact_test1);
    printf("\n\n");
    display_all_levels_diary(test);
    contact_test1->appointments = creat_apointem();
    contact_test1->appointments->next = creat_apointem();
    view_apo(contact_test1);

    return 0;
}

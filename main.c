#include "cell.h"
#include "level_list.h"
#include "Diary.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include "contact.h"
int main() {
    t_d_contact *contact_test1 = create_contact();
    t_d_contact *contact_test2 = create_contact();
    int i = compareStrings(contact_test1->firstname,contact_test2->firstname);
    printf("i = %d",i);

    return 0;
}

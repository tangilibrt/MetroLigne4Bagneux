#include "cell.h"
#include "level_list.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include "diary.h"



int N = 10;

int main() {
//    t_d_list *list_test = create_mt_list_from_n(N);
//    align_and_display(list_test);
//
//    int search_time = research_time(list_test, 100000, N);

// ----------------------------------------------------------------------------------------------------------


//    int search_value = 256;
//    int complexity_classic = classic_search(list_test, search_value);
//    if (complexity_classic == -1) {
//        printf("Value %d not found.\n", search_value);
//    } else {
//        printf("Value %d found in %d steps with classical search.\n", search_value, complexity_classic);
//    }
//    int optimized_complexity = optimized_search(list_test, search_value);
//    if (optimized_complexity == -1) {
//        printf("Value %d not found.\n", search_value);
//    } else {
//        printf("Value %d found in %d steps with optimized search\n", search_value, optimized_complexity);
//    }
//
// ----------------------------------------------------------------------------------------------------------
//                     Part 3 : Diary
// ----------------------------------------------------------------------------------------------------------
    entry *entry1 = create_entry("nicolas","flasque");
    entry *entry2 = create_entry("nils","foincoin");
    entry *entry3 = create_entry("tanguy","flibert");
    entry *entry4 = create_entry("ilyes","ben");
    diary *diary1 = create_diary();
    add_entry(diary1,entry1);
    add_entry(diary1,entry2);
    add_entry(diary1,entry3);
    add_entry(diary1,entry4);
    align_and_display_diary(diary1);

    return 0;
}

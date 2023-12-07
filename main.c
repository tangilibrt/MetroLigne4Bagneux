#include "cell.h"
#include "level_list.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>


int N = 10;

int main() {
    t_d_list *list_test = create_mt_list_from_n(N); // create a list with 10 levels and (2^10)-1 cells = 1023 cells
    align_and_display(list_test); // display the list

    int search_time = research_time(list_test, 100000, N);


    return 0;
}

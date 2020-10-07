#include <stdio.h>

#include "header.h"


/** Runs cmp tests
 */
void test_cmp(void) {
    int pass_count = 0;
    int total_count = 3;
    if (linear_comp((char *)"abc", (char *)"abc") == 0)
        pass_count++;
    if (linear_comp((char *)"abcd", (char *)"abc") > 0)
        pass_count++;
    if (linear_comp((char *)"ab", (char *)"abc") < 0)
        pass_count++;
    printf("%d/%d Cmp tests passed\n", pass_count, total_count);
}


/** Runs reverse cmp tests
 */
void test_reverse_cmp(void) {
    int pass_count = 0;
    int total_count = 3;

    if (reverse_comp((char *)"abc", (char *)"abc") == 0)
        pass_count++;
    if (reverse_comp((char *)"aba", (char *)"cba") < 0)
        pass_count++;
    if (reverse_comp((char *)"acb", (char *)"aba") > 0)
        pass_count++;
    printf("%d/%d Reverse cmp tests passed\n", pass_count, total_count);
}


/** Runs sort tests
 */
void test_sort() {
    int pass_count = 0;
    int total_count = 2;
    char *unsorted[3] = {"z", "y", "x"};
    start_qsort(unsorted, 3, linear_comp);
    char *sorted[3] = {"x", "y", "z"};
    int pass = 1;
    for (int i = 0; i < 3; i++) {
        if (sorted[i] != unsorted[i]){
            pass = 0;
            break;
        }
    }
    if (pass)
        pass_count++;

    char *unsorted2[3] = {"yb", "xc", "za"};
    start_qsort(unsorted2, 3, reverse_comp);
    char *sorted2[3] = {"za", "yb", "xc"};
    pass = 1;
    for (int i = 0; i < 3; i++) {
        if (sorted2[i] != unsorted2[i]){
            pass = 0;
            break;
        }
    }
    if (pass)
        pass_count++;
    printf("%d/%d Sort tests passed\n", pass_count, total_count);
}

/** Runs all tests
 */

void run_tests(void)
{
    test_cmp();
    test_reverse_cmp();
    test_sort();
}

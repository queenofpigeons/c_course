#ifdef T
#ifdef PT

#include <stdio.h>
#include <string.h>

#include "../inc/templates.h"

/*
 * Print given number
 *
 * number: number for print
 */
void TEMPLATE(print, T) (T number) {
    #if PT == INT
        printf("[+]\t%d\n", number);
    #elif PT == CHAR
        printf("[+]\t%c\n", number);
    #elif PT == SHORT
        printf("[+]\t%hd\n", number);
    #elif PT == DOUBLE
        printf("[+]\t%lf\n", number);
    #endif
}

/*
 * Print error message at dump start
 */
void TEMPLATE(start_err_print, T)(void) {
    #if T == INT
        printf("\n\nCrashdump of INT stack\n");
    #elif T == CHAR
        printf("\n\nCrashdump of CHAR stack\n");
    #elif T == SHORT
        printf("\n\nCrashdump of SHORT stack\n");
    #elif T == DOUBLE
        printf("\n\nCrashdump of DOUBLE stack\n");
    #endif
    printf("---------------------\n");
}

/*
 * Print error message at dump end
 */
void TEMPLATE(end_err_print, T)(void) {
    printf("---------------------\n");
    printf("End of crashdump\n\n");
}

#endif
#endif

#ifdef T

#include <stdio.h>

#include "templates.h"

/*
 * Print given number
 *
 * number: number for print
 */
void TEMPLATE(print, T) (int index, T number) {
    #if T == int
        printf("[+]\t%d\n", index, number);
    #elif T == char
        printf("[+]\t%c\n", index, number);
    #elif T == short
        printf("[+]\t%hd\n", index, number);
    #elif T == double
        printf("[+]\t%lf\n", index, number);
    #endif
}

/*
 * Print error message at dump start
 */
void TEMPLATE(start_err_print, T)(void) {
    #if T == int
        printf("\n\nCrashdump of INT stack\n");
    #elif T == char
        printf("\n\nCrashdump of CHAR stack\n");
    #elif T == short
        printf("\n\nCrashdump of SHORT stack\n");
    #elif T == double
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

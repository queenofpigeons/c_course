#include "inc/defines.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    TEMPLATE(Stack, double) *st;
    st = calloc(1, TEMPLATE(getStructSize, double)());

    printf("Create DOUBLE stack\n\n");
    TEMPLATE(createStack, double)(st, 2);

    for (int i = 1; i <= 8; i++) {
        printf("Push %d to stack\n", i);
        TEMPLATE(push, double)(st, i);
    }

    printf("\nStack now:\n");
    for (int i = 1; i <= 8; i++) {
        printf("%lf ", TEMPLATE(pop, double)(st));
    }

    printf("\n\nDelete DOUBLE stack");
    TEMPLATE(deleteStack, double)(st);

    return 0;
}

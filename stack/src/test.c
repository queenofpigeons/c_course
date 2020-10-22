#include "defines.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    TEMPLATE(Stack, char) *st;
    st = calloc(1, TEMPLATE(getStructSize, char)());

    printf("Create CHAR stack\n\n");
    TEMPLATE(createStack, char)(st, 3);

    for (char i = 1; i <= 5; i++) {
        printf("Push %d to stack\n", i);
        TEMPLATE(push, char)(st, i);
    }

    printf("\nStack now:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", TEMPLATE(pop, char)(st));
    }

    printf("\n\nDelete CHAR stack");
    TEMPLATE(deleteStack, char);

    return 0;
}

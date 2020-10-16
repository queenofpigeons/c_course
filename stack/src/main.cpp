
#include "defines.hpp"

int main(int argc, char *argv[]) {

    //struct TEMPLATE(Stack, int) st;
    struct Stack_int st;
    TEMPLATE(createStack, int)(&st, 10);
    TEMPLATE(push, int)(&st, 3);
    printf("Я жив!\n");
}
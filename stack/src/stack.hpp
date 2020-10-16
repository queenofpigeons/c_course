#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>

#ifdef T
#include "templates.hpp"

struct TEMPLATE(Stack, T) {
    uint64_t canary_start;
	int size;
	int capacity;
	int* data;
    uint64_t canary_end;
};

void TEMPLATE(createStack, T)(struct TEMPLATE(Stack, T) *stack, int capacity);
void TEMPLATE(deleteStack, T)(struct TEMPLATE(Stack, T) *stack);
void TEMPLATE(push, T)(struct TEMPLATE(Stack, T) *stack, T value);
T TEMPLATE(pop, T)(struct TEMPLATE(Stack, T) *stack);
#endif
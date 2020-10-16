#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>

#ifdef T
#include "templates.hpp"

const uint64_t canary_value = 0xCAFEBABE0BAD1DEA;

struct TEMPLATE(Stack, T) {
    uint64_t canary_start;
	int size;
	int capacity;
	int* data;
    uint64_t canary_end;
};

void TEMPLATE(createStack, T)(struct TEMPLATE(Stack, T) *stack, int capacity) {
	stack->capacity = capacity;
	stack->size = 0;
	stack->data = (int*)calloc(stack->capacity, sizeof(T));
}

void TEMPLATE(deleteStack, T)(struct TEMPLATE(Stack, T) *stack) {
	stack->capacity = -1;
	stack->size = -1;
	free(stack->data);
	free(stack);
}

void TEMPLATE(push, T)(struct TEMPLATE(Stack, T) *stack, T value) {
	stack->data[++stack->size] = value;
}

T TEMPLATE(pop, T)(struct TEMPLATE(Stack, T) *stack) {
	return stack->data[stack->size--];
}
#endif
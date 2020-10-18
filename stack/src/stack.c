#ifdef T

#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdint.h>

#include "templates.h"

#ifndef STACK_C
#define STACK_C

const uint64_t canary_value = 0xCAFEBABE0BAD1DEA;

#endif

struct TEMPLATE(Stack, T) {
    uint64_t canary_start;
    int size;
    int capacity;
    T *data;
    uint64_t canary_end;
} __attribute__((aligned(sizeof(unsigned long))));

int TEMPLATE(getStructSize, T) (void) {
    return sizeof(uint64_t) * 2 + sizeof(int) * 2 + sizeof(T *);
}

void TEMPLATE(createStack, T) (struct TEMPLATE(Stack, T) *stack, int capacity) { 
    stack->capacity = capacity;
    stack->size = 0;
    stack->data = (T*)calloc(stack->capacity, sizeof(T));
}

void TEMPLATE(deleteStack, T) (struct TEMPLATE(Stack, T) *stack) {
    stack->capacity = -1;
    stack->size = -1;

    free(stack->data);
    free(stack);
}

void TEMPLATE(push, T) (struct TEMPLATE(Stack, T) *stack, T value) {
    stack->data[++stack->size] = value;
}

T TEMPLATE(pop, T) (struct TEMPLATE(Stack, T) *stack) {
    return stack->data[stack->size--];
}

#endif

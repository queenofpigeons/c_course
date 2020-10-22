#ifdef T

#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "../inc/templates.h"
#include "../inc/print.h"

#ifndef STACK_C
#define STACK_C

enum STACK_ERR
{
    STACK_OK,
    WRONG_STRUCT_CANARY_START,
    WRONG_STRUCT_CANARY_END,
    WRONG_DATA_CANARY_START,
    WRONG_DATA_CANARY_END,
    WRONG_DATA_POINTER,
    WRONG_SIZE,
    WRONG_CAPACITY
};

const uint64_t canary_value = 0xCAFEBABE0BAD1DEA;

#endif

struct TEMPLATE(Stack, T) {
    #ifdef CHECK_CANARY
    uint64_t canary_start;
    #endif

    int size;
    int capacity;
    T *data;

    #ifdef CHECK_CANARY
    uint64_t canary_end;
    #endif
} __attribute__((aligned(sizeof(unsigned long))));

/*
 * Returns the size of the Stack structure
 */
int TEMPLATE(getStructSize, T)(void) {
    return sizeof(uint64_t) * 2 + sizeof(int) * 2 + sizeof(T *);
}

/*
 * Initialize the stack structure
 *
 * stack: pointer to Stack sructure to initialize
 * capacity: desired stack capacity
 */
void TEMPLATE(createStack, T)(struct TEMPLATE(Stack, T) *stack, int capacity) {
    stack->capacity = capacity;
    stack->size = 0;
    int n_blocks = stack->capacity;
    int size = sizeof(T);

    // if we want to have canary values before and after stack, we must account for them when allocating memory
    #ifdef CHECK_CANARY
    n_blocks = sizeof(T) / sizeof(char) + 2 * sizeof(canary_value) / sizeof (char);
    size = sizeof(char);
    #endif

    void *allocated = calloc(n_blocks, size);

    #ifdef CHECK_CANARY
    (uint64_t *)allocated++;
    #endif

    stack->data = (T*)allocated;
}

/*
 * Delete the stack structure
 *
 * stack: pointer to Stack sructure to delete
 */
void TEMPLATE(deleteStack, T)(struct TEMPLATE(Stack, T) *stack) {
    stack->capacity = -1;
    stack->size = -1;

    free(stack->data);
    free(stack);
}

/*
 * Push value to stack
 *
 * stack: pointer to Stack sructure
 * value: value to push
 */
void TEMPLATE(push, T)(struct TEMPLATE(Stack, T) *stack, T value) {
    if (stack->capacity == stack->size) {
        uint64_t new_size = sizeof(T) * stack->capacity * 2;
        T *data_end = stack->data + stack->capacity;

        #ifdef CHECK_CANARY
        (T *)stack->data--;
        new_size += sizeof(stack->canary_start) * 2;
        #endif
        
        void *reallocated = realloc(stack->data, new_size);
        stack->data = reallocated;
        memset(++data_end, 0, sizeof(T) * stack->capacity);
        
        #ifdef CHECK_CANARY
        memset(++data_end, canary_value, sizeof(uint64_t));
        #endif
    }
    if (TEMPLATE(verifyStack, T)(stack)) {
        TEMPLATE(dumpStack, T)(stack);

        return;
    }
    stack->data[++stack->size] = value;
}

/*
 * Pops value from stack and returns it
 *
 * stack: pointer to Stack sructure
 */
T TEMPLATE(pop, T)(struct TEMPLATE(Stack, T) *stack) {
    if (TEMPLATE(verifyStack, T)(stack)) {
        TEMPLATE(dumpStack, T)(stack);
        stack->size--;

        return 0;
    }
    return stack->data[stack->size--];
}

/*
 * Checks the validity of stack structure depending on the specified security level
 *
 * stack: pointer to Stack sructure
 */
int TEMPLATE(verifyStack, T)(struct TEMPLATE(Stack, T) *stack) {
    #ifdef CHECK_STACK
    if (stack->capacity < 0)
        return WRONG_CAPACITY;
    if (stack->size < 0)
        return WRONG_SIZE;
    if (!(stack->data))
        return WRONG_DATA_POINTER;
    #ifdef CHECK_CANARY
    if (stack->canary_start != canary_value)
        return WRONG_STRUCT_CANARY_START;
    if (stack->canary_end != canary_value)
        return WRONG_STRUCT_CANARY_END;

    #endif
    #endif
    
    return STACK_OK;
}

/*
 * Dumps stack and print it out
 *
 * stack: pointer to Stack structue
 */
void TEMPLATE(dumpStack, T)(struct TEMPLATE(Stack, T) *stack) {
    TEMPLATE(start_err_print, T)();
    for (int i = stack->size; i > 0; i--) {
        TEMPLATE(print, T)(stack->data[i]);
    }
    TEMPLATE(end_err_print, T)();
}

#endif

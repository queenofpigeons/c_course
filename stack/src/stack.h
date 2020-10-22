#ifdef T

#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

#include "templates.h"
#include "print.h"

typedef struct TEMPLATE(Stack, T) TEMPLATE(Stack, T);

int TEMPLATE(getStructSize, T)(void);

void TEMPLATE(createStack, T)(struct TEMPLATE(Stack, T) *stack, int capacity);
void TEMPLATE(deleteStack, T)(struct TEMPLATE(Stack, T) *stack);
void TEMPLATE(push, T)(struct TEMPLATE(Stack, T) *stack, T value);
T TEMPLATE(pop, T)(struct TEMPLATE(Stack, T) *stack);
int TEMPLATE(verifyStack, T)(struct TEMPLATE(Stack, T) *stack);
void TEMPLATE(dumpStack, T)(struct TEMPLATE(Stack, T) *stack);

#endif

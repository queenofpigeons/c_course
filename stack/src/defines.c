#ifndef DEFINES_C
#define DEFINES_C

#include "../inc/templates.h"
#include "../inc/defines.h"

#define INT     0
#define CHAR    1
#define SHORT   2
#define DOUBLE  3

#ifdef T
#undef T
#endif
#ifdef PT
#undef PT
#endif
#define PT CHAR
#define T char
#include "../src/stack.c"
#include "../src/print.c"

#ifdef T
#undef T
#endif
#ifdef PT
#undef PT
#endif
#define PT SHORT
#define T short
#include "../src/stack.c"
#include "../src/print.c"

#ifdef T
#undef T
#endif
#ifdef PT
#undef PT
#endif
#define PT DOUBLE
#define T double
#include "../src/stack.c"
#include "../src/print.c"

#ifdef T
#undef T
#endif
#ifdef PT
#undef PT
#endif
#define PT INT
#define T int
#include "../src/stack.c"
#include "../src/print.c"

#endif

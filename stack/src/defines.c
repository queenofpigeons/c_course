#ifndef DEFINES_H
#define DEFINES_H

#include "templates.h"
#include "defines.h"

#ifdef T
#undef T
#endif
#define T char
#include "stack.c"
#include "print.c"

#ifdef T
#undef T
#endif
#define T short
#include "stack.c"
#include "print.c"

#ifdef T
#undef T
#endif
#define T double
#include "stack.c"
#include "print.c"

#ifdef T
#undef T
#endif
#define T int
#include "stack.c"
#include "print.c"

#endif

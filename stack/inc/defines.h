#ifndef DEFINES_H
#define DEFINES_H

#include "../inc/templates.h"

#ifdef T
#undef T
#endif
#define T int
#include "../inc/stack.h"
#include "../inc/print.h"

#ifdef T
#undef T
#endif
#define T char
#include "../inc/stack.h"
#include "../inc/print.h"

#ifdef T
#undef T
#endif
#define T short
#include "../inc/stack.h"
#include "../inc/print.h"

#ifdef T
#undef T
#endif
#define T double
#include "../inc/stack.h"
#include "../inc/print.h"

#endif

#include <stdio.h>
#include "calc.h"

#define MAXVAL 100


static int sp = 0;
static double val[MAXVAL];

void push (double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else
        printf("Ошибка: Стек полон %g не помещается\n", f);
}

double pop (void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("Ошибка: стек пуст\n");
        return 0.0;
}

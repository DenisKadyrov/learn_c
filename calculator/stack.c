#include <stdio.h>

#define MAXVAL 100


extern int sp;
extern double val[];

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

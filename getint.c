#include <stdio.h>
#include <ctype.h>
#include "calculator/calc.h"

int getint(int *);

int main()
{
    int n, array[10];
    for (n = 0; n < 10 & getint(&array[n]) != EOF; n++)
        ;
}

int getint(int *pn)
{
    int sign, c;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c == EOF)
        ungetch(c);
    return c;
}


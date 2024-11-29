#include <stdio.h>

int getlin(char *s, int lim)
{
    int c, i;
    for (i = 0; (c = getchar()) != EOF && i < lim && c != '\n'; i++)
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return i;
}

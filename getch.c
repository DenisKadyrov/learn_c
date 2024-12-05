#include <stdio.h>
#define BUFERSIZE 100


static char buf[BUFERSIZE];
static int bufp = 0;


int getch (void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch (int c)
{
    if (bufp >= BUFERSIZE)
        printf("Буфер переполнен\n");
    else
        buf[bufp++] = c;
}

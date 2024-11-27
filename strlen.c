#include <stdio.h>


int strl(char *);


int main()
{
    char array[] = "Hello";
    int len = strl(array);
    printf("%d\n", len);
}

int strl(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

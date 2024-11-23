/* convert string to integer */
#include <stdio.h>


int atoi(char[]);

int main(void)
{
    int res;
    char st[] = "219";
    res = atoi(st);
    printf("%d\n", res);
}

int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) 
        n = n * 10 + (s[i] - '0');
    return n;
}

/* lower: convert c to lower case char; only for ASCII */
#include <stdio.h>


int lower(int c);


int main(void)
{
    char c = 'B';
    printf("%c\n", lower(c));
}

int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    return c;
}

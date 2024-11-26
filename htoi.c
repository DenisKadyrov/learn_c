#include <stdio.h>
#include <ctype.h>


int htoi(char []);

int main(void)
{
    printf("%d\n", (int) "0xF5")
}
/* function for convert string of hexadecimal into equivalent integer value */
int htoi(char s[])
{
    int i, n;
    char c;
    
    n = 0;
    for (i = 0; isspace(s[i]); i++)
        ;
    if (s[i++] != '0' && s[i] != 'x' && s[i] != 'X')
        return n;
    for (; (c = s[i]) != '\0' && (isdigit(c) || isalpha(c)); i++) {
        if (isdigit(c))
    }
}

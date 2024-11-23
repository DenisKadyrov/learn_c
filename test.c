#include <stdio.h>
#include <limits.h>


void change_str(char s[]);

int main()
{
    char sch[] = "hello";
    change_str(sch);
    printf("%s\n", sch);
}

void change_str(char s[])
{
    s[0] = 'H';
}

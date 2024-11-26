#include <stdio.h>

void printd(int);

int main(void)
{
    // use example
    printd(100);
}

/* function for print number as char sequence */
void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) 
        printd(n / 10);
    putchar(n % 10 + '0');
}

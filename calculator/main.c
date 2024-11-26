#include <stdlib.h>
#include <stdio.h>
#include "calc.h"

#define MAXOP 100

int main ()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push (atof (s));
                break; case '+':
                push (pop() + pop());
                break;
            case '*':
                push (pop() * pop());
                break;
            case '-':
                op2 = pop();
                push (pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push (pop() / op2);
                else
                    printf("Ошибка делания на нуль\n");
                break;
            case '\n':
                printf("%.8g\n", pop());
                break;
            default:
                printf("Ошибка: неизвастная операция %s\n", s);
                break;
        }
    }
    return 0;
}

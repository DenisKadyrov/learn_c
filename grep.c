#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getlin(char *s, int max);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long linen = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 1 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("Not right parameter\n");
                    argc = 0;
                    found = -1;
                    break;
            }
    if (argc != 1)
        printf("Use this example: grep -x -n pattern\n");
    else 
        while ((c = getlin(line, MAXLINE)) > 0) {
            linen++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld:", linen);
                printf("%s", line);
                found++;
            }
        }
    return found;
}

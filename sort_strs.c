/* Program structure:
Read all lines
Sort array of pointers to char
Write sorted lines
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsor(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *t, char *s);
int strcm(char *t, char *s);

int main(int argc, char *argv[]) 
{
    int nlines; // number of lines
    int numeric = 0;
    if (argc > 1 && strcm(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsor((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) (numeric ? numcmp : strcm));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("Error: so many lines\n");
        return 1;
    }
}

#define MAXLEN 1000

int getlin(char *, int);
char *alloc(int);

/* That function read all lines and return number of lines
   And return -1 if number of lines more then MAXLINE of len cant locate in memory
*/
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getlin(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

int strcm(char *s, char *t)
{
    for (; *s == *t; t++, s++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else 
        return 0;
}

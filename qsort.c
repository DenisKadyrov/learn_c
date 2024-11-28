#include <stdio.h>



/* function for sort array of pointers to char */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    int strcmp(char *s, char *t);
    
    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, last, left);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* function for swap 2 element of array */
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int strcmp(char *s, char *t)
{
    for (; *s == *t; t++, s++)
        if (*s = '\0')
            return 0;
    return *s - *t;
}

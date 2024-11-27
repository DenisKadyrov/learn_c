#include <stdio.h>


void qsort(int[], int, int);

int main(void)
{
    // use example
    int i;
    int arr[] = {1, 5, 35, 6, 8, 32, 5, 57, 76, 3};
    qsort(arr, 0, 10);
    for (i = 0; i < 10; i++)
        printf("%d\n", arr[i]);
}

/* function for sort int array of integer */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);
    
    if (left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, last, left);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* function for swap 2 element of array */
void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

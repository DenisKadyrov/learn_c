/* binary search function 
O(n) = log n
*/
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (v[mid] < x)
            low = mid + 1;
        else if (v[mid] > x)
            high = mid - 1;
        else
            return v[mid];
    }
    return -1;


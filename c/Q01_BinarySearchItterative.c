// itterative method
#include <stdio.h>
#include <stdlib.h>
int binarysearch(int a[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (key > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, key;
    printf("Enter the number of element:");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter the element:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the key:");
    scanf("%d", &key);
    int res;
    res = binarysearch(a, n, key);
    if (res != -1)
    {
        printf("Yes %d is present at %d postion", key, (res + 1));
    }
    else
    {
        printf("%d not found in the array !!", key);
    }

    return 0;
}

#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        else
            return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int size, arr[100], search;
    printf("Number of elements: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("Enter value to search for: ");
    scanf("%d", &search);

    int pos = binarySearch(arr, 0, size-1, search);
    if (pos == -1)
        printf("Value not found\n");
    else
        printf("Found value at %d position\n", pos);
}


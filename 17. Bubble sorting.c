#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n\n");
}

int main()
{
    int arr[] = {1, 10, 90, 100, -1, 11, 9, 14, 3, 2, 20, 19};
    int n = sizeof(arr) / sizeof(int);

    printf("Array Before Sorting:\n");
    PrintArray(arr, n);

    BubbleSort(arr, n);

    printf("Array After Sorting:\n");
    PrintArray(arr, n);
}
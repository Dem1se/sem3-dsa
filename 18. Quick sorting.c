#include <stdio.h>

void swap(int *A, int *B)
{
   int temp = *A;
   *A = *B;
   *B = temp;
}

int Partition(int arr[], int start, int end)
{
   int pivot = end;
   int j = start;
   for (int i = start; i < end; ++i)
   {
      if (arr[i] < arr[pivot])
      {
         swap(arr[i], arr[j]);
         ++j;
      }
   }
   swap(arr[j], arr[pivot]);
   return j;
}

void Quicksort(int arr[], int start, int end)
{

   if (start < end)
   {
      int p = Partition(arr, start, end);
      Quicksort(arr, start, p - 1);
      Quicksort(arr, p + 1, end);
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
   int arr[] = {1, 10, 11, 9, 14, 3, 2, 20, 19, 43, 57, 3, 2};
   int n = sizeof(arr) / sizeof(int);

   printf("Array Before Sorting:\n");
   PrintArray(arr, n);

   Quicksort(arr, 0, n - 1);
   printf("Array After Sorting:\n");
   PrintArray(arr, n);
}
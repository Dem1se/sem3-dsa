#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct heapstruct
{
    int capacity;
    int size;
    int *a;
};

typedef struct heapstruct *pq;

pq initialize(int capacity, int initValue)
{
    pq h;
    h = (struct heapstruct *)malloc(sizeof(struct heapstruct));
    h->a = (int *)malloc((capacity + 1) * sizeof(int));
    h->capacity = capacity;
    h->size = 0;
    h->a[0] = initValue;
    return h;
}

void insert(int x, pq h)
{
    int i;
    if (h->size == h->capacity)
        printf("\nFull");
    else
    {
        for (i = ++h->size; h->a[i / 2] > x; i = i / 2)
            h->a[i] = h->a[i / 2];
        h->a[i] = x;
    }
}

int delmin(pq h)
{
    int i, mina, lasta, child;
    if (h->size == 0)
        return h->a[0];
    else
    {
        mina = h->a[1];
        lasta = h->a[h->size--];
        for (i = 1; i * 2 <= h->size; i = child)
        {
            child = i * 2;
            if (child != h->size && h->a[child + 1] < h->a[child])
                child++;
            if (lasta > h->a[child])
                h->a[i] = h->a[child];
            else
                break;
        }
        h->a[i] = lasta;
        return mina;
    }
}

void display(pq h)
{
    int i;
    for (i = 1; i <= h->size; i++)
        printf("\nThe data is: %d", h->a[i]);
}

void main()
{
    pq heap;
    int size, initValue, value, choice;
    printf("\nEnter the maximum number of elements for the Priority Queue:");
    scanf("%d", &size);
    printf("\nEnter the initial element :");
    scanf("%d", &initValue);
    heap = initialize(size, initValue);
    while (choice != 4)
    {
        printf("\nPriority Queue");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Choice >>> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the Data : ");
            scanf("%d", &value);
            insert(value, heap);
            break;
        case 2:
            printf("\nThe deleted element is: %d", delmin(heap));
            break;
        case 3:
            display(heap);
            break;
        case 4:
            break;
        }
    }
}

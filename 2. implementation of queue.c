#include <stdio.h>

#define MAXLEN 100

struct q_rec
{
    int element[MAXLEN];
    int front;
    int rear;
    int size;
};

typedef struct q_rec queue;
queue init();
int isempty(queue Q);
int isfull(queue Q);
int front(queue Q);
queue enqueue(queue Q, int x);
queue dequeue(queue Q);
void display(queue Q);

queue init()
{
    queue Q;
    Q.front = 0;
    Q.rear = -1;
    Q.size = 0;
    return Q;
}

int isempty(queue Q)
{
    return (Q.size == 0);
}

int isfull(queue Q)
{
    return (Q.size == MAXLEN);
}

int front(queue Q)
{
    if (isempty(Q))
    {
        printf("\nQueue is empty\n");
        return -1;
    }
    else
        return Q.element[Q.front];
}

queue enqueue(queue Q, int x)
{
    if (isfull(Q))
    {
        printf("\nQueue is full\n");
        return Q;
    }
    else
    {
        ++Q.rear;
        if (Q.rear == MAXLEN)
            Q.rear = 0;
        Q.element[Q.rear] = x;
        Q.size++;
        return Q;
    }
}

queue dequeue(queue Q)
{
    if (isempty(Q))
    {
        printf("\nQueue is empty\n");
        return Q;
    }
    else
    {
        printf(" dequeued element %d", Q.element[Q.front]);
        ++Q.front;
        Q.size--;
        if (Q.front == MAXLEN)
            Q.front = 0;
        return Q;
    }
}

void display(queue Q)
{
    int i;
    if (isempty(Q))
        printf("\nQueue is empty\n");
    else
    {
        i = Q.front;
        while (1)
        {
            printf("\n%d", Q.element[i]);
            if (i == Q.rear)
                break;
            if (++i == MAXLEN)
                i = 0;
        }
    }
}

void main()
{
    int choice, y;
    queue Q;
    Q = init();
    printf("\n\t QUEUE OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    8;

    do
    {
        printf("\n\t 1.Enqueue\n\t 2.Dequeue\n\t 3.Front element\n\t 4.DISPLAY\n\t 5.EXIT");
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("\n Enter the Element:");
            scanf("%d", &y);
            Q = enqueue(Q, y);
            break;
        }
        case 2:
        {
            Q = dequeue(Q);
            break;
        }
        case 3:
        {
            y = front(Q);
            printf("\n Element at the front of the queue%d:", y);
            break;
        }
        case 4:
        {
            display(Q);
            break;
        }

        case 5:
            printf("\n\t EXIT POINT ");
            break;
        }
    } while (choice != 5);
}

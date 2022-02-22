#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 50

typedef struct
{
    int stack[STACK_SIZE]; // fized size stack
    int top;
} Stack;

Stack *init()
{
    Stack *stk;
    stk = (Stack *)malloc(sizeof(Stack));
    stk->top = -1;
    return stk;
}

void push(Stack *stk, int val)
{
    if (stk->top == STACK_SIZE - 1)
    {
        puts("Stack already full. Value not pushed");
        return;
    }
    stk->stack[++stk->top] = val;
}

int pop(Stack *stk)
{
    if (stk->top == -1)
        return 1;
    return stk->stack[stk->top--];
}

void display(Stack *stk)
{
    for (int i = stk->top; i >= 0; --i)
        printf("%d) %d\n", i, stk->stack[i]);
}

int main()
{
    Stack *stk = init();
    int choice = 0, val;
    3;

    while (choice != 4)
    {
        puts("\n----Menu-----");
        puts("1. Push");
        puts("2. Pop");
        puts("3. Display Stack");
        puts("4. Exit");
        printf(">>> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &val);
            push(stk, val);
            break;
        case 2:
            printf("The popped value: %d", pop(stk));
            break;
        case 3:
            display(stk);
            break;
        case 4:
            break;
        default:
            puts("Invalid choice given.");
            break;
        }
    }
}

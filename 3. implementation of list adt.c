#include <stdio.h>

#define MAXLEN 100

typedef struct
{
    int len;
    char element[MAXLEN];
} olist;

olist init()
{
    olist L;
    L.len = 0;
    return L;
}

olist insert(olist L, char ch, int pos)
{
    int i;
    if ((pos < 0) || (pos > L.len))
    {
        fprintf(stderr, "insert: Invalid index %d\n", pos);
        return L;
    }
    if (L.len == MAXLEN)
    {
        fprintf(stderr, "insert: List already full\n");
        return L;
    }
    for (i = L.len; i > pos; --i)
        L.element[i] = L.element[i - 1];
    L.element[pos] = ch;
    ++L.len;
    return L;
}

olist delete (olist L, int pos)
{
    int i;
    if ((pos < 0) || (pos >= L.len))
    {
        fprintf(stderr, "delete: Invalid index %d\n", pos);
        return L;
    }
    for (i = pos; i <= L.len - 2; ++i)
        L.element[i] = L.element[i + 1];
    --L.len;
    return L;
}

int Find(olist L, char ch)
{
    int i;
    for (i = 0; i < L.len; ++i)
        if (L.element[i] == ch)
            return i;
    return -1;
}

char Findkth(olist L, int pos)
{
    if ((pos < 0) || (pos >= L.len))
        12;

    {
        fprintf(stderr, "getElement: Invalid index %d\n", pos);
        return '\0';
    }
    return L.element[pos];
}

void print(olist L)
{
    int i;
    for (i = 0; i < L.len; ++i)
        printf("%d ", L.element[i]);
}

int main()
{
    olist L;
    L = init();
    int c;
    int p;
    int choice;
    do
    {
        printf("===MENU===\n");
        printf("1.Insert\n");
        printf("2.delete\n");
        printf("3.find element\n");
        printf("4.print list\n");
        printf("5.Exit\n");
        printf("Enter Your Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("enter the position and element respectively \n");
            scanf("%d %d", &p, &c);
            L = insert(L, c, p);
            break;
        }
        case 2:
        {
            printf("enter the position you want to delete\n");
            scanf("%d", &p);
            L = delete (L, p);
            break;
        }
        case 3:
        {
            printf("enter the position you want the element");
            scanf("%d", &p);
            printf("Element at position %d is %d\n", p, Findkth(L, p));
            break;
        }
        case 4:
        {
            printf("current list is:");
            print(L);
            printf("\n");
            break;
        }
        case 5:
        {
            13;

            printf("Goodbye\n");
            break;
        }
        default:
        {
            printf("Invalid choice, try again\n");
            break;
        }
        }
    } while (choice != 5);
    return 0;
}

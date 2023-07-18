#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node *llist;
llist init();
llist insert(llist L, int ch, int pos);
llist delete(llist L, int pos);
llist find(llist L, int ch);
int findkth(llist L, int pos);
void printlist(llist L);
void deletelist(llist L);
void reverse(llist L);
llist init()
{
    llist L;
    /* Create the dummy node */
    L = (struct node *)malloc(sizeof(struct node));
    L->value = -1;
    L->next = NULL;
    return L;
}
llist insert(llist L, int ch, int pos)
{
    int i;
    llist p, n;
    if (pos < 0)
    {
        printf("invalid index");
        return L;
    }
    p = L;
    i = 0;
    while ((i < pos) && (p != NULL))
    {
        p = p->next;
        ++i;
    }
    if (p == NULL)
    {
        printf("Invalid index");
        return L;
    }
    n = (struct node *)malloc(sizeof(struct node));
    n->value = ch;
    n->next = p->next;
    p->next = n;
    return L;
}
llist delete(llist L, int pos)
{
    int i;
    llist p, temp;
    if (pos < 0)
    {
        printf("invalid index");
        return L;
    }
    p = L;
    i = 0;
    while ((i < pos) && (p->next != NULL))
    {
        p = p->next;
        ++i;
    }
    if (p->next == NULL)
    {
        printf("Invalid index ");
        return L;
    }
    temp = p->next;
    p->next = temp->next;
    free(temp);
    return L;
}
llist find(llist L, int ch)
{
    llist p;
    p = L->next;
    while (p != NULL)
    {
        if (p->value == ch)
            return p;
        p = p->next;
    }
    return NULL;
}
int findkth(llist L, int pos)
{
    int i;
    llist p;
    i = 0;
    p = L->next;
    while ((i < pos) && (p != NULL))
    {
        p = p->next;
        ++i;
    }
    if (p == NULL)
    {
        printf("Invalid index ");
        return -1;
    }
    return p->value;
}
void printlist(llist L)
{
    llist p;
    p = L->next;
    while (p != NULL)
    {
        printf("%d", p->value);
        p = p->next;
    }
}
void deletelist(llist L)
{
    llist p, temp;
    p = L->next;
    L->next = NULL;
    while (p != NULL)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
}
void main()
{
    typedef struct node *llist;
    int n, pos, ch;
    llist L;
    L = init();
    insert(L, 1, 0);
    insert(L, 2, 1);
    insert(L, 3, 2);
    char i;
    do
    {
        printf("1. insert\n2. delete\n3. find\n4. findkth\n5. print list\n6. delete list\nEnter choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
        {
            printf("\nEnter character and position: ");
            scanf("%d%d", &ch, &pos);
            L = insert(L, ch, pos);
            printf("\nCurrent list= ");
            printlist(L);
            break;
        }
        case 2:
        {
            printf("\nEnter position: ");
            scanf("%d", &pos);
            L = delete (L, pos);
            break;
        }
        case 3:
        {
            printf("\nEnter character to be found: ");
            scanf("%d", &ch);
            printf("\nPosition of %d is %d", ch, find(L, ch));
            break;
        }
        case 4:
        {
            printf("\nEnter position: ");
            scanf("%d", &pos);
            printf("\nElement at %d is %d", pos, findkth(L, pos));
            break;
        }
        case 5:
        {
            printf("\nThe list: ");
            printlist(L);
            break;
        }
        case 6:
        {
            printf("\nList has been deleted.");
            deletelist(L);
            break;
        }
        case 7:
        {
            reverse(L);
            printlist(L);
            break;
        }
        default:
        {
            printf("\nInvalid choice");
            break;
        }
        }
        printf("\nDo you want to continue?<< Enter y if yes >> ");
        scanf("%s", &i);
    } while (i == 'y');
}

void reverse(llist L)
{
    llist cur = L->next, prev = NULL, actual_next;
    while (cur)
    {
        actual_next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = actual_next;
    }
    L->next = prev;
}

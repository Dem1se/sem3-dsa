#include <stdio.h> 
#include <malloc.h> 
struct node 
{ 
int element; 
struct node *next; 
}; 
typedef struct node *STACK; 
int isempty(STACK s); 
STACK create(); 
void push(STACK s, int x); 
void pop(STACK s); 
int topelement(STACK S); 
void display(STACK s); 
int isempty(STACK s) 
{ 
return s->next == NULL; 
} 
STACK create() 
{ 
STACK s; 
s = (struct node *)malloc(sizeof(struct node)); 
s->element = -1; 
s->next = NULL; 
return s; 
} 
void push(STACK s, int x) 
{ 
STACK newnode; 
newnode = (struct node *)malloc(sizeof(struct node)); 
newnode->element = x; 
newnode->next = s->next; 
s->next = newnode; 
} 
void pop(STACK s) 
{ 
STACK temp; 
if (isempty(s)) 
printf("Stack is empty"); 
else 
{ 
temp = s->next; 
s->next = temp->next; 
printf("popped element %d", temp->element); 
free(temp); 
} 
} 
int topelement(STACK s) 
{ 
STACK temp; 
if (!isempty(s)) 
{ 
temp = s->next; 
return temp->element; 
} 
 else 
{ 
printf("stack is empty"); 
return -1; 
} 
} 
 
void display(STACK s) 
{ 
STACK p; 
if (!isempty(s)) 
{ 
printf("\n The elements in STACK \n"); 
p = s->next; 
while (p != NULL) 
{ 
printf("\n%d", p->element); 
p = p->next; 
} 
} 
else 
printf("\n The STACK is empty"); 
} 
void main() 
{ 
int choice, x; 
STACK s; 
s = create(); 
printf("\n\t STACK OPERATIONS USING ARRAY"); 
printf("\n\t--------------------------------"); 
printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.TOP ELEMENT\n\t 4.DISPLAY\n\t 5.EXIT"); 
do 
{ 
printf("\n Enter the Choice:"); 
scanf("%d", &choice); 
switch (choice) 
{ 
case 1: 
{ 
printf("\n Enter the Element:"); 
scanf("%d", &x); 
push(s, x); 
break; 
} 
case 2: 
{ 
pop(s); 
break; 
} 
case 3: 
{ 
x = topelement(s); 
printf("\n Element on the top of the stack %d:", x); 
break; 
} 
case 4: 
display(s); 
break; 
case 5: 
printf("\n\t EXIT POINT "); 
break; 
} 
} while (choice != 5); 
}

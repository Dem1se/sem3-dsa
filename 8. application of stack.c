// infix to postfix

#include <stdio.h>
#include <string.h>

#define STACK_SIZE 50

typedef struct
{
    int top;
    char stack[STACK_SIZE];
} Stack;

void push(Stack *s, char val)
{
    if (s->top == STACK_SIZE - 1)
        return;
    s->stack[++s->top] = val;
}

char pop(Stack *s)
{
    if (s->top == -1)
        return '\0';
    return s->stack[s->top--];
}

int isOperator(char c)
{
    if (c == '^' || c == '/' || c == '*' || c == '+' || c == '-')
        return 1;
    else
        return 0;
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '/' || op == '*')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    Stack s = {.top = -1};
    int pi = 0;

    for (int i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];

        if (ch == ' ')
        {
            continue;
        }
        else if (!isOperator(ch))
        {
            if (ch == ')')
            {
                while (s.stack[s.top] != '(')
                    postfix[pi++] = pop(&s);
                pop(&s); // remove the l. bracket from stack as well
            }
            else if (ch == '(')
            {
                push(&s, ch);
            }
            else
            {
                postfix[pi++] = ch;
            }
        }
        else
        {
            while (1)
            {
                if (precedence(s.stack[s.top]) >= precedence(ch) && s.stack[s.top] != '(')
                    postfix[pi++] = pop(&s);
                else
                {
                    push(&s, ch);
                    break;
                }
            }
        }
    }

    // empty the stack at the end
    while (s.top != -1)
        postfix[pi++] = pop(&s);

    postfix[pi++] = '\0'; // null terminate the string :)
}

int main()
{
    char infix[100], postfix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s", postfix);
}

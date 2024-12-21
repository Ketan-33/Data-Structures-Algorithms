// infix to postfix

#include <stdio.h>
#include <string.h>

struct Stack
{
    int top;
    char S[20];
};

int isEmpty(struct Stack *s1)
{
    if (s1->top == -1)
    {
        return 0;
    }
    else
        return 1;
}

void push(struct Stack *s1, int element)
{
    if (s1->top == 20 - 1)
    {
        printf("***Stack overflow***\n");
    }
    else
    {
        s1->top++;
        s1->S[s1->top] = element;
        // printf("%d pushed\n", element);
    }
}
char pop(struct Stack *s1)
{
    if (s1->top >= 0)
    {
        char result = s1->S[s1->top];
        s1->top--;
        return result;
    }
    else
    {
        printf("***Stack underflow***\n");
    }
}
char peek(struct Stack *s1)
{
    if (s1->top == -1)
    {
        printf("***Stack Empty***\n");
        return -1;
    }
    else
    {
        return s1->S[s1->top];
    }
}
// checking the precedence of an operator
int checkprecedence(char operator)
{
    if (operator== '+' || operator== '-')
    {
        return 1;
    }
    else if (operator== '*' || operator== '/')
    {
        return 2;
    }
    else if (operator== '^')
    {
        return 3;
    }
    else
        return -1;
}

// infix expression to postfix
void infixToPostfix(char *infix)
{
    struct Stack stack;
    stack.top = -1;
    char postfix[strlen(infix)];
    int index = 0;

    for (int i = 0; i < strlen(infix); i++)
    {
        char c = infix[i];
        if (isalnum(c))
        {
            postfix[index] = c;
            index++;
            // printf("%c", c);
        }
        else if (c == '(')
        {
            push(&stack, c);
        }
        else if (c == ')') // pop till '('
        {
            while ((isEmpty(&stack) == 1) && peek(&stack) != '(')
            {
                postfix[index] = pop(&stack);
                index++;
            }
            if (isEmpty(&stack) == 1 && peek(&stack) != '(')
            {
                printf("***Invalid expression***\n");
                return;
            }
            else
            {
                pop(&stack); // Pop '('
            }
        }
        else
        {
            while ((isEmpty(&stack) == 1) && checkprecedence(c) <= checkprecedence(peek(&stack)))
            {
                postfix[index] = pop(&stack);
                index++;
            }
            push(&stack, c);
        }
    }

    // Popping remaining operator
    while (isEmpty(&stack) == 1)
    {
        postfix[index] = pop(&stack);
        index++;
    }
    printf("\n");

    printf("-->Postfix expression: ");
    for (int i = 0; i < index; i++)
    {
        printf("%c", postfix[i]);
    }
}

int main()
{
    char infixExpression[20];
    printf("\n-->Enter a infix expression: ");
    scanf("%s", infixExpression);
    int open = 0, close = 0;
    for (int i = 0; i <= strlen(infixExpression); i++)
    {
        if (infixExpression[i] == '(')
        {
            open++;
        }
        else if (infixExpression[i] == ')')
        {
            close++;
        }
    }

    if (open == close)
    {
        infixToPostfix(infixExpression);
        return 0;
    }
    else
    {
        printf("***Invalid expression***\n");
        return 0;
    }
}

#include <stdio.h>
#include <stdlib.h>

const int max = 20;

struct STACK
{
    char S[20];
    int top;
};

void push(struct STACK *s1, char element)
{
    if (s1->top == max - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        s1->top++;
        s1->S[s1->top] = element;
        printf("%c pushed\n", element);
    }
}

char pop(struct STACK *s1)
{
    if (s1->top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        char ele = s1->S[s1->top];
        s1->top--;
        printf("Popped element -> %c\n", ele);
        return ele;
    }
}

int peek(struct STACK s1)
{
    if (s1.top == -1)
    {
        printf("Stack Empty\n");
        return -1;
    }
    else
    {
        printf("Top element is -> %c\n", s1.S[s1.top]);
        return s1.S[s1.top];
    }
}

int isEmpty(struct STACK *s1)
{
    if (s1->top == -1)
    {
        return 0;
    }
    else
        return 1;
}

int main()
{
    struct STACK s1;
    s1.top = -1;
    int CHSE;
    char a;
    while (1)
    {
        printf("Enter '1' to PUSH\t'2' to POP\t'3' to PEEK\tAny other to exit\n");
        scanf("%d", &CHSE);
        switch (CHSE)
        {
        case 1:
            printf("Enter character to push: ");
            scanf(" %c", &a);
            push(&s1, a);
            break;
        case 2:
            pop(&s1);
            break;
        case 3:
            peek(s1);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

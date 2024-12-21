// Evaluation of postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
    int top;
    int S[20];
};

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
int pop(struct Stack *s1)
{
    if(s1->top>=0){
        int result = s1->S[s1->top];
        s1->top--;
        return result;
    }
    else{
        printf("***Stack underflow***\n");
    }
}

// Evaluate a postfix expression
int evaluatePostfix(char *exp)
{
    struct Stack s1;
    s1.top=-1;
    int i, result,temp1,temp2;
  

    for (i = 0;i<=strlen(exp);i++)
    {
        if (isdigit(exp[i]) == 1)
        {
            push(&s1, exp[i] -'0');
        }
        else{
            switch (exp[i])
            {
            case '+':
                temp1 = pop(&s1);
                temp2 = pop(&s1);

                push(&s1, temp2 + temp1);
                break;
            case '-':
                temp1 = pop(&s1);
                temp2 = pop(&s1);

                push(&s1, temp2 - temp1);
                break;
            case '*':
                temp1 = pop(&s1);
                temp2 = pop(&s1);

                push(&s1, temp2 * temp1);
                break;
            case '/':
                temp1 = pop(&s1);
                temp2 = pop(&s1);

                push(&s1, temp2 / temp1);
                break;
            default:
                break;
            }
        }
    }
    //printf("%d", s1.top);
    result = pop(&s1);
    return result;
}


int main()
{
    char postfixExpression[100];
    printf("-->Enter a postfix expression: ");
    scanf("%s", postfixExpression);
    int result = evaluatePostfix(postfixExpression);
    if (result != -1)
    {
        printf("-->Result: %d\n", result);
    }
    else
    {
        printf("***Error: Invalid expression***\n");
    }
    return 0;
}

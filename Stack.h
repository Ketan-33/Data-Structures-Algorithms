#include<stdio.h>
struct STACK{
    int S[100];
    int top;
};

void push(struct STACK s1, char element)
{
    if(s1.top==100-1){
        printf("Stack overflow");
    }
    else{
        s1.top++;
        s1.S[s1.top]= element;
       // printf("%d pushed successfully\n",element);
    }
}

int pop(struct STACK s1)
{
    if (s1.top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        int ele = s1.S[s1.top];
        s1.top--;
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
        return s1.S[s1.top];
    }
}
int main()
{   
    struct STACK s1;
    s1.top=-1;
    push(s1,33);
    push(s1,44);
    push(s1,55);

    pop(s1);

    peek(s1);

    return 0;

}
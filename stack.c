#include<stdio.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
void push(int element)
{
    if(top==SIZE-1)
    {
        printf("Empty stack\n");
        return;
    }
    stack[++top]=element;
}
int pop()
{
    if(top==-1)
        return -9999;
    return stack[top--];
}
void display()
{
    int i;
     if(top==-1)
     {
         printf("Empty stack\n");
         return;
     }
     printf("Stack contents:\n");
     for(i=top;i>=0;i--)
     {
         printf("%d\n",stack[i]);
     }
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    printf("the element popped is %d\n",pop());
    printf("the element popped is %d\n",pop());
    printf("the element popped is %d\n",pop());
    printf("the element popped is %d\n",pop());
    printf("the element popped is %d\n",pop());
    display();
    printf("%d",stack[0]);

}

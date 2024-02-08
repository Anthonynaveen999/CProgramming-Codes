#include<stdio.h>
int stack[4];
int top=-1;
void push(int data)
{
    stack[++top]=data;
}
int pop()
{
    if(top==-1)
    {
        return -9999;
    }
    return stack[top--];
}
void display()
{
    printf("stack contents:\n");
    for(int i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}
int main()
{
    int data,x,i=7;
    push(50);
    push(40);
    push(30);
    push(20);
    display();
    do{
    if((x=pop())==-9999)
    {
        printf("stack empty\n");
        return;
    }
        printf("the data deleted from stack is %d\n",x);
        i--;
    }while(i>=0);


}

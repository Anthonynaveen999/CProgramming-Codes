#include<stdio.h>
#include<ctype.h>
char stack[20];
int top=-1;
void push(char x)
{
    stack[++top]=x;
}
int pop()
{
    if(top==-1)
        return -1;
    else
        return stack[top--];
}
int isEmpty()
{
    return top ==-1;
}
int priority(char opr)
{
    if(opr=='(' || opr==')')
        return 0;
    else if(opr=='+' || opr=='-')
        return 1;
    else if(opr=='*' || opr=='%')
        return 2;
    return 0;
}
int main()
{
    char exp[20];
    int x,i=0;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    printf("Output:");
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(isalnum(exp[i]))
        {
            printf("%c",exp[i]);
        }
        else if(exp[i]==')')
        {
            while((x=pop())!='(')
            {
                printf("%c",x);
            }
        }
        else
        {
            while(!isEmpty() && priority(stack[top]) >= priority(exp[i]))
            {
                printf("%c",pop());
            }
            push(exp[i]);
        }
        i++;
    }
    while(!isEmpty())
    {
        printf("%c",pop());
    }
    return 0;
}

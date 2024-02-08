#include<stdio.h>
int largest(int*a,int*b,int*c);
int main()
{
int a,b,c,max;
scanf("%d%d%d",&a,&b,&c);
max=largest(&a,&b,&c);
printf("the max is %d",max);
return 0;
}
int largest(int*a,int*b,int*c+)
{

    if(*a>*b && *a>*c)
    {
      return *a;
    }
    else if(*b>*a && *b>*c)
    {
        return *b;

    }
    else
        return *c;
}

#include<stdio.h>
typedef struct date{
int hr;
int min;
int sec;
struct date *next;
}date;
void display(date *start)
{
    date *temp=start;
    while(temp != NULL)
    {
        printf("The Time is %d:%d:%d\n",temp->hr,temp->min,temp->sec);
        temp=temp->next;
    }
}
int main()
{
    date *d1;
    d1=(date*)malloc(sizeof(date));
    d1->hr=5;
    d1->min=30;
    d1->sec=45;
    date *d2;
    d2=(date*)malloc(sizeof(date));
    d1->next=d2;
    d2->hr=6;
    d2->min=30;
    d2->sec=45;
    display(d1);
    return 0;
}

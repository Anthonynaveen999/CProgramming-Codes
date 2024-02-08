#include<stdio.h>
typedef struct Time{
    int hour,minute,second;
    //int minute;
    //int second;
    struct Time *next ;
}TIME;
void display(TIME *temp)
{
    int i=1;
    while (temp!=NULL)
    {
        printf("Time %d:%d:%d:%d\n",i,temp->hour,temp->minute,temp->second);
        temp=temp->next;
        i+=1;
    }
}

int main()
{
    TIME *t1=(TIME*)malloc(sizeof(TIME));
    printf("Enter the 1st time in the format hh:mm:ss:");
    scanf("%d:%d:%d",&t1->hour,&t1->minute,&t1->second);
    printf("entered time: %d:%d:%d\n",t1->hour,t1->minute,t1->second);
    t1->next=NULL;

    TIME* t2=(TIME*)malloc(sizeof(TIME));
    printf("Enter the 2nd time in the format hh:mm:ss:");
    scanf("%d:%d:%d",&t2->hour,&t2->minute,&t2->second);
    printf("entered time: %d:%d:%d\n",t2->hour,t2->minute,t2->second);
    t2->next=NULL;
    t1->next=t2;
    printf("The times are:\n");
    display(t1);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
typedef struct data{
    int data;
    struct data *next;
}node;
node*start=NULL;
node *getnode(int data)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
    temp->data=data;
    return temp;
}
void insert_at_start(int data)
{
    node *temp=getnode(data);
    temp->next=start;
    start=temp;
}
void insert_at_middle(int key,int data)
{
    node*temp=start;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            node*nn=getnode(data);
            nn->next=temp->next;
            temp->next=nn;
            return;
        }
        temp=temp->next;
    }
    printf("element not found\n");
}
void search_value(int key)
{
    node*temp=start;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            printf("the element is present\n");
            return;
        }
        temp=temp->next;
    }
    printf("the element is not present\n");
}
void delete_node(int key)
{
    node*cur=start;
    node*prev=NULL;
    if(cur->next==NULL)
    {
        start=NULL;
        free(cur);
        return;
    }
    while(cur!=NULL)
    {
        if(cur->data==key)
        {
            prev->next=cur->next;
            free(cur);
            return;
        }
        prev=cur;
        cur=cur->next;
    }
    printf("element %d not found!\n",key);
}
void display_list()
{
    node*temp=start;
    if(start==NULL)
    {
        printf("list empty\n");
        return;
    }
    printf("The linked list:");
    while(temp!=NULL)
    {
      printf(" %d",temp->data);
      temp=temp->next;
    }
    printf("\n");

}
int main()
{
    int option,key,data;
    do{
    printf("###########MENU#############\n");
    printf("1. Insert at start\n2: Insert after given data\n3: Delete node with given data\n4: Search for given value\n5: Display list\n6: Exit\n");
    printf("Enter option:");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
        printf("Enter the element:");
        scanf("%d",&data);
        insert_at_start(data);
        display_list();
        break;
        case 2:printf("Enter an existing element:");
        scanf("%d",&key);
        printf("Enter the element:");
        scanf("%d",&data);
        insert_at_middle(key,data);
        display_list();
        break;
        case 3:printf("Enter an existing element:");
        scanf("%d",&key);
        delete_node(key);
        display_list();
        break;
        case 4:printf("Enter the search key:");
        scanf("%d",&key);
        search_value(key);
        break;
        case 5:display_list();
        break;
        case 6:printf("Program terminating...");
        return ;
        default:printf("Invalid option\n");

    }
    }while(option>=0 || option<0);
return 0;
}

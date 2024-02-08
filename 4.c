#include<stdio.h>
#include<stdlib.h>
typedef struct data{
    int data;
    struct data *right;
    struct data *left;
}node;
node*start=NULL;
node *getnode(int data)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->right=NULL;
    temp->left=NULL;
    temp->data=data;
    return temp;
}
void insert_at_start(int data)
{
    node *temp=getnode(data);
    if(start==NULL)
    {
       temp->right=start;
       start=temp;
       return;
    }
    temp->right=start;
    start->left=temp;
    start=temp;
}
void insert_before(int key,int data)
{
    node *temp=start;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            node*nn=getnode(data);
            if(temp->left==NULL)
            {
                nn->right=temp;
                nn->left=temp->left;
                start=nn;
                return;
            }

            nn->right=temp;
            nn->left=temp->left;
            temp->left->right=nn;
            temp->left=nn;
            return;
        }
        temp=temp->right;
    }
    printf("element not found\n");
}
void delete_node(int key)
{
    node*temp=start;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            temp->right->left=temp->left;
            temp->left->right=temp->right;
            free(temp);
            return;
        }
        temp=temp->right;
    }
    printf("element %d not found!",key);
}
void display_list()
{
    node*temp=start;
    if(start==NULL)
    {
        printf("list empty");
        return;
    }
    printf("The linked list:");
    while(temp!=NULL)
    {
      printf(" %d",temp->data);
      temp=temp->right;
    }
    printf("\n");

}
int main()
{
    int option,key,data;
    do{
    printf("###########MENU#############\n");
    printf("1. Insert at start\n2: Insert before given data\n3: Delete node with given data\n4: Display list\n5: Exit\n");
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
        insert_before(key,data);
        display_list();
        break;
        case 3:printf("Enter an existing element:");
        scanf("%d",&key);
        delete_node(key);
        display_list();
        break;
        case 4:display_list();
        break;
        case 5:printf("Program terminating...");
        return ;
        default:printf("Invalid option\n");
        break;
    }
    }while(option>=0 || option<0);
return 0;
}


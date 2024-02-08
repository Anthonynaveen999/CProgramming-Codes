#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
node*getnode(int value)
{
    node*temp=(node*)malloc(sizeof(node));
    temp->data=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
node*insert(node*root,int value)
{
    if(root==NULL)
        return getnode(value);
    if(value<root->data)
        root->left=insert(root->left,value);
    else
        root->right=insert(root->right,value);
    return root;
}
node*maxvalue(node*n)
{
    if(n->right==NULL)
        return n;
    else
        return maxvalue(n->right);
}
node*delete_node(node*root,int key)
{
    if(root==NULL)
    {
        printf("Element not found\n");
        return ;
    }
    else if(key<root->data)
        root->left=delete_node(root->left,key);
    else if(key>root->data)
        root->right=delete_node(root->right,key);
    else
    {
        if(root->left!=NULL && root->right!=NULL)
        {
            node*temp=maxvalue(root->left);
            root->data=temp->data;
            root->left=delete_node(root->left,root->data);
        }
        else if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        else if(root->right==NULL)
            {
                node*temp=root;
                root=root->left;
                free(temp);
            }
        else
            {
                node*temp=root;
                root=root->right;
                free(temp);
            }

    }
    return root;
}
void inorder(node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }

}
void postorder(node*root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }

}
void preorder(node*root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }

}
int main()
{
    node*root=NULL;
    int opt,value,key;
    printf("**main menu**\n");
    printf("1.insert\n2.inorder\n3.delete a node\n4.preorder\n5.postorder\n6.exit\n");
    while(1)
    {
        printf("enter your option:");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:printf("enter the value:");
            scanf("%d",&value);
            root=insert(root,value);
            break;
            case 2:inorder(root);
            break;
            case 3:printf("Enter the key:");
            scanf("%d",&key);
            root=delete_node(root,key);
            break;
            case 4:postorder(root);
            break;
            case 5:preorder(root);
            break;
            case 6:return;
            default:printf("incorrect option\n");
        }
    }
    return 0;
}

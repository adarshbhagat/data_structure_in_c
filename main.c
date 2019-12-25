#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left,*right;
};
struct node *root=NULL;
void insert(int key)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->key=key;
    ptr->right=ptr->left=NULL;
    if(root==NULL)
    {
        root=ptr;
        return;
    }
    struct node *temp=root;
    while(1)
    {
        if(temp->key>key)
        {
            if(temp->left==NULL)
            {
                temp->left=ptr;
                return;
            }
            temp=temp->left;
        }
        else if(temp->key<key)
        {
            if(temp->right==NULL)
            {
                temp->right=ptr;
                return;
            }
            else
                temp=temp->right;
        }
        else
            return;
    }
}
void search(int value)
{
    struct node *temp=root;
    while(temp->key!=value)
    {
        if(value<temp->key)
        {temp=temp->left;
        if(temp==NULL)
        {
            printf("unavailable\n");
            return;
        }
        }
        else
            {temp=temp->right;
            if(temp==NULL)
            {
                printf("unavailable\n");
            return;
            }
            }
    }
    printf("available\n");
}
void in_order(struct node *temp)
{
    if(temp==NULL)
        return;
    in_order(temp->left);
    printf("%d\t",temp->key);
    in_order(temp->right);
}
void findmax(struct node *temp)
{
    if(temp->right==NULL)
        printf("%d\n",temp->key);
    else
        findmax(temp->right);
}
void findmin(struct node *temp)
{
    if(temp->left==NULL)
        printf("%d\n",temp->key);
    else
        findmin(temp->left);
}
void erase(int value)
{
    struct node *del,*temp=root,*prev_tmp=NULL;
    while(temp->key!=value)
    {
        prev_tmp=temp;
        if(value<temp->key)
            temp=temp->left;
        else
            temp=temp->right;
    }
    while(1)
    {
        del=temp;
        if(temp->left==temp->right&&temp->right==NULL)
        {
            if(prev_tmp->left==temp)
            {
                prev_tmp->left=NULL;
            }
            else
            {
                prev_tmp->right=NULL;
            }
            free(temp);
            return;
        }
        else if(temp->right==NULL&&temp->left!=NULL)
        {
            temp->key=temp->left->key;
            del=temp->left;
            temp->left=temp->left->left;
            free(del);
            return;
        }
        else if(temp->left==NULL&&temp->right!=NULL)
        {
            temp->key=temp->right->key;
            del=temp->right;
            temp->right=temp->right->right;
            free(del);
            return;
        }
        else
        {
            struct node *ptr=temp;
            while(ptr->left!=NULL)
                ptr=ptr->left;
            int x=ptr->key;
            erase(ptr->key);
            temp->key=x;
            return;
        }
    }
}
struct node* makeempty(struct node *temp)
{
    if(temp==NULL)
        return;
    makeempty(temp->left);
    makeempty(temp->right);
    return NULL;
}
int main()
{
    insert(3);
    insert(1);
    insert(6);
    insert(5);
    insert(2);
    insert(1);
    in_order(root);
    printf("\n");
    findmin(root);
    findmax(root);
    search(3);
    search(1);
    search(2);
    search(10);
    erase(2);
    in_order(root);
    root=makeempty(root);
    in_order(root);
}

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node *root=NULL;
struct node* create(int ele)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->data=ele;
    return (ptr);
}
int main()
{
   int ele;
   struct node *root,*left,*right,*data;
   printf("enter an element");
   scanf("%d",&ele);
   root=create(ele);
   root->left=create(6);
   root->right=create(16);
   root->left->left=create(4);
   root->left->right=create(8);
   root->right->right=create(19);
   printf("\nROOT LEFT:%d   ROOT:%d   ROOT RIGHT:%d",root->left->data,root->data,root->right->data);
   printf("\nROOT LEFT LEFT:%d     ROOT LEFT RIGHT:%d",root->left->left->data,root->left->right->data);
   printf("\nROOT KA RIGHT KA RIGHT:-%d",root->right->right->data);
   return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data,index;
    struct node *next;
};
struct array
{
    char x[20];
    struct node *ptr;
};
struct node* insert(int x,int ind,struct node *start)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node*));
    ptr->data=x;
    ptr->index=ind;
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;
    }
    else
    {
        struct node *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=ptr;
    }
    return start;
};
int main()
{
    printf("enter the no. of vertices\n");
    int n,p,ind,vall;
    scanf("%d",&n);
    struct array a[n];
    for(int i=0;i<n;i++)
        a[i].ptr=NULL;
    for(int i=0;i<n;i++)
    {
        printf("enter name for %d index\n",i);
        scanf("%s",a[i].x);
        printf("press no. of vertices to be attached with the vertex of %s :- ",a[i].x);
        scanf("%d",&p);
        for(int j=0;j<p;j++)
        {
            printf("enter value and index\n");
            scanf("%d%d",&ind,&vall);
            a[i].ptr=insert(ind,vall,a[i].ptr);
        }
    }
    for(int i=0;i<n;i++)
    {
        struct node *temp=a[i].ptr;
        printf("cities connected with %s is :- ",a[i].x);
        while(temp!=NULL)
        {
            printf("%s\t",a[temp->index].x);
            temp=temp->next;
        }
        printf("\n");
    }
    return 0;
}

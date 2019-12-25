#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void create(unsigned capacity)
{
        start=(struct node*)malloc(sizeof(struct node));
        struct node *temp;
        temp=start;
        for(int i=1;i<capacity;i++)
        {
            temp->next=(struct node*)malloc(sizeof(struct node));
            temp=temp->next;
        }
        temp=NULL;
        printf("stack created\n");
}
void push(int data,int t)
{
    struct node*temp=start;
    while(t!=0)
    {
        temp=temp->next;
        t--;
    }
    temp->data=data;
}
void print(int t)
{
    struct node *temp;
    temp=start;
    while(t!=0)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        t--;
    }
    printf("\n");
}
void pop(int t)
{
    struct node *temp=start;
    while(t!=1)
        {
            temp=temp->next;
            t--;
        }
    printf("%d\n",temp->data);
}
void peek(int t)
{
    struct node *temp=start;
    while(t!=1)
        {
            temp=temp->next;
            t--;
        }
    printf("%d\n",temp->data);
}
void push(int,int);
void pop();
void create(unsigned int);
void peek ();
void print();
int main()
{
    int i,n,xyz=0,max_v;
    printf("enter the capacity of stack\n");
            scanf("%d",&i);
            create(i);
            max_v=i;
    for(;;)
    {
        printf("press 1. to peek\n");
        printf("press 2. to push\n");
        printf("press 3. to pop\n");
        printf("press 4. to display\n");
        printf("press 5. to check available space\n");
        printf("press 6. to exit\n");
        scanf("%d",&n);
        switch (n)
        {
        case 2:
            if(xyz==max_v)
                break;
            printf("enter the data value\n");
            scanf("%d",&i);
            push(i,xyz);
            xyz++;
            break;
        case 3:
            if(xyz==0)
                break;
            pop(xyz);
            xyz--;
            break;
        case 4:
            print(xyz);
            break;
        case 5:
            printf("%d space available\n",max_v-xyz);
            break;
        case 6:
            return 0;
            break;
        case 1:
            if(xyz==0)
                break;
            peek(xyz);
            break;
        default:
            printf("invalid entry\n");
        }
    }
    return 0;
}

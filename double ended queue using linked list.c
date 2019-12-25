#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *start=NULL;
void enqueue()
{
    printf("enter the value of element: ");
    if(start==NULL)
    {
        start=(struct node*)malloc(sizeof(struct node));
        start->next=NULL;
        scanf("%d",&start->data);
    }
    else
    {
        struct node *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        struct node *s=(struct node*)malloc(sizeof(struct node));
        s->next=NULL;
        scanf("%d",&s->data);
        temp->next=s;
    }
}
void no_of_element()
{
    int count=0;
    struct node *temp=start;
    while(temp!=0)
    {
        temp=temp->next;
        count++;
    }
    printf("no of element is: %d\n",count);
}
void dequeue()
{
    if(start==NULL)
        printf("queue is empty\n");
    else
    {
        struct node *temp=start;
        start=start->next;
        free(temp);
    }
}
void peek()
{
    if(start==NULL)
        printf("queue is empty\n");
    else
        printf("element is : %d\n",start->data);
}
void dequeuer()
{
    struct node *temp=start;
    if(start==NULL)
        return;
    if(start->next==NULL)
    {
        start=NULL;
        free(temp);
    }
    else
    {
        struct node *prev=temp;
        temp=temp->next;
        while(temp->next!=NULL)
            {
                prev=temp;
                temp=temp->next;
            }
            free(temp);
            prev->next=NULL;
    }
}
void enqueuef()
{
    printf("enter the value of element: ");
    if(start==NULL)
    {
        start=(struct node*)malloc(sizeof(struct node));
        start->next=NULL;
        scanf("%d",&start->data);
    }
    else
    {
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->next=start;
        scanf("%d",&temp->data);
        start=temp;
    }
}
void display()
{
    struct node *temp=start;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("1.for enqueue from rear\n");
        printf("7.for enqueue from front\n");
        printf("2.for dequeue from front\n");
        printf("6.for dequeue from reverse\n");
        printf("3.for check no. of element\n");
        printf("4.peek\n");
        printf("10.To display\n");
        printf("5.exit\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
            enqueue();
        else if(choice==2)
            dequeue();
        else if(choice==3)
            no_of_element();
        else if(choice==4)
            peek();
        else if(choice==6)
            dequeuer();
        else if(choice==10)
            display();
        else if(choice==5)
            return 0;
        else if(choice==7)
            enqueuef();
        else
            printf("please enter a valid no.\n");
        printf("\n");
    }
}

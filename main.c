#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data,priority;
    struct node* next;
};
struct node *front=NULL,*rear=NULL;
void display()
{
    struct node *temp=front;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void enqueue()
{
    int priority;
    printf("enter priority :");
    scanf("%d",&priority);
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->priority=priority;
    ptr->next=NULL;
    printf("enter the data :");
    scanf("%d",&ptr->data);
    if(front==NULL)
    {
        front=ptr;
        rear=ptr;
    }
    else
    {
        struct node *temp=front;
        while(temp->priority<=priority&&temp->next!=NULL)
            temp=temp->next;
        ptr->next=temp->next;
        temp->next=ptr;
        if(temp==rear)
            rear=ptr;
    }
}
void dequeue()
{
    if(front==NULL)
        return;
    else if(front->next==NULL)
    {
        free(front);
        front=rear=NULL;
    }
    else
    {
        struct node *temp;
        temp=front;
        front=front->next;
        free(temp);
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("1.for enqueue\n");
        printf("2.for dequeue\n");
        printf("3.for display\n");
        printf("4. for Exit\n");
        printf("enter your choice :");
        scanf("%d",&choice);
        if(choice==1)
            enqueue();
        else if(choice==2)
            dequeue();
        else if(choice==3)
            display();
        else if(choice == 4)
            return 0;
        printf("\n");
    }
}

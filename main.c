#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};
struct node *start=NULL,*last=NULL;
void insert_at_begin(int);
void traverse_from_end();
void insert_at_end(int);
void traverse();
void delete_from_begin();
void delete_from_end();
int count = 0;
int main()
{
    int input, data;
    for (;;) {
      printf("1. Insert an element at beginning of linked list.\n");
      printf("2. Insert an element at end of linked list.\n");
      printf("3. Traverse linked list from beginning.\n");
      printf("4. Delete element from beginning.\n");
      printf("5. Delete element from end.\n");
      printf("6. Exit\n");
      printf("7. traverse from end\n");

      scanf("%d",&input);

      if (input == 1) {
         printf("Enter value of element\n");
         scanf("%d", &data);
         insert_at_begin(data);
      }
      else if (input == 2) {
         printf("Enter value of element\n");
         scanf("%d", &data);
         insert_at_end(data);
      }
      else if (input == 3)
         traverse();
      else if (input == 4)
         delete_from_begin();
      else if (input == 5)
         delete_from_end();
        else if (input == 7)
        traverse_from_end();
      else if (input == 6)
         break;
      else
         printf("Please enter valid input.\n");
   }

   return 0;
}
void insert_at_begin(int x)
{
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    count++;
    if (start == NULL)
    {
        t->data = x;
        t->next = NULL;
        start=t;
        t->prev=NULL;
        last=t;
    }
    else
    {
        start->prev=t;
        t->data = x;
        t->next = start;
        start = t;
        t->prev = NULL;
    }
}
void insert_at_end(int x)
{
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    count++;
    if(start == NULL)
    {
        t->data = x;
        t->next = NULL;
        start=t;
        t->prev=NULL;
        last=t;
    }
    else
    {
        last->next=t;
        t->data=x;
        t->next=NULL;
        t->prev=last;
        last=t;
    }
}
void traverse()
{
    struct node *temp;
    printf("there are %d elements in the linked list\n",count);
    if(start == NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        temp=start;
        printf("this is the entered linked list\n");
        while (temp->next!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
void traverse_from_end()
{
    struct node *temp;
    printf("there are %d elements in the linked list\n",count);
    if(start == NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        temp=last;
        printf("this is the entered linked list\n");
        while (temp->prev!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->prev;
        }
        printf("%d\n",temp->data);
    }
}
void delete_from_begin()
{
    struct node *temp;
    if(start == NULL)
    {
        printf("there is no element to be deleted\n");
        return ;
    }
    temp=start->next;
    free(start);
    start=temp;
    temp->prev=NULL;
    count--;
}
void delete_from_end()
{
    if(start == NULL)
    {
        printf("the list is empty\n");
        return;
    }
    else if(start->next == NULL)
    {
       count--;
       free(start);
       start = NULL;
       return;
    }
    else
    {
        struct node *t;
        t=last->prev;
        t->next=NULL;
        free(last);
        last=t;
        count--;
    }
}

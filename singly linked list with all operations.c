#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void insert_at_begin(int);
void insert_at_end(int);
void traverse();
void delete_from_begin();
void delete_from_end();
void display_rev();
void display_rev_rec(struct node *curr);
int count = 0;
int main()
{
    int input, data;
    for (;;) {
      printf("1. Insert an element at beginning of linked list.\n");
      printf("2. Insert an element at end of linked list.\n");
      printf("3. Traverse linked list.\n");
      printf("4. Delete element from beginning.\n");
      printf("5. Delete element from end.\n");
      printf("6. Exit\n");
      printf("7. print in reverse(recursive)\n");
      printf("8. print in reverse(iterative)\n");
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
      else if (input == 6)
         break;
      else if (input == 7)
      {
         display_rev_rec(start);
         printf("\n");
      }
      else if(input==8)
        display_rev();
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
    }
    else
    {
        t->data=x;
        t->next=start;
        start = t;
    }
}
void insert_at_end(int x)
{
    struct node *temp;
    count++;
    if(start == NULL)
    {
        start=malloc(sizeof(struct node));
        start->data=x;
        start->next=NULL;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next = (struct node*)malloc(sizeof(struct node));
        temp=temp->next;
        temp->data=x;
        temp->next=NULL;
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
        struct node *t,*u;
        t=start;
        u=t->next;
        while(u->next!=NULL)
        {
            t=u;
            u=u->next;
        }
        free(u);
        t->next=NULL;
        count--;
    }
}
void display_rev()
{
    struct node *ptr,*temp;
    ptr=start;
    while (ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    while(ptr!=start)
    {
    for(temp=start;temp->next!=ptr;temp=temp->next);
    printf("%d\t",ptr->data);
    ptr=temp;
    }
    printf("%d\n",ptr->data);
}
void display_rev_rec(struct node *curr)
{
    if(curr==NULL)
    {
        return;
    }
    else
    {
        display_rev_rec(curr->next);
        printf("%d\t",curr->data);
    }
}

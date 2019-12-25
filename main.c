#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    unsigned capacity;
    int *array;
};
struct stack* create(unsigned capacity)
{
    struct stack* stack =(struct stack*)malloc(sizeof(struct stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int*)malloc(capacity * sizeof(int));
    printf("Created\n");
    return(stack);
}
void push(int data,struct stack* begin)
{
    if(begin->top+1==begin->capacity)
    {
        printf("stack is full\n");
        return;
    }
    begin->array[begin->top+1]=data;
    (begin->top)++;
}
void print(struct stack* begin)
{
    int i=0;
    while(begin->top+1!=i)
    {
        printf("%d ",begin->array[i]);
        i++;
    }
    printf("\n");
}
int pop(struct stack* begin)
{
    if(begin->top == -1)
    {
        printf("no element is in stack\n");
        return -1;
    }
    begin->top=begin->top-1;
    return(begin->array[begin->top+1]);
}
void status(struct stack* begin)
{
    if(begin->top==-1)
    {
        printf("stack  is empty\n");
        printf("there are %d space available\n",(begin->capacity-((begin->top)+1)));
        return;
    }
    if(begin->capacity==begin->top+1)
    {
        printf("stack is full\n");
        return;
    }
    printf("there are %d space available\n",(begin->capacity-((begin->top)+1)));
}
int peek(struct stack *begin)
{
    if(begin->top==-1)
    {
        printf("stack is empty\n");
        return -1;
    }
    return(begin->array[begin->top]);
}
void status (struct stack*);
int pop(struct stack*);
void push(int,struct stack*);
struct stack* create(unsigned int);
int peek (struct stack*);
int main()
{
    struct stack* begin;
    int i,n;
    printf("enter the capacity of stack\n");
            scanf("%d",&i);
            begin=create(i);
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
            printf("enter the data value\n");
            scanf("%d",&i);
            push(i,begin);
            break;
        case 3:
            printf("%d\n",pop(begin));
            break;
        case 4:
            print(begin);
            break;
        case 5:
            status(begin);
            break;
        case 6:
            return 0;
            break;
        case 1:
            printf("%d\n",peek(begin));
            break;
        default:
            printf("invalid entry\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r,c,i,j;
    printf("enter the no of rows and columns\n");
    scanf("%d%d",&r,&c);
    int **arr = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
         arr[i] = (int *)malloc(c * sizeof(int));
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
    {
        scanf("%d",*(arr+i)+j);
    }
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
    {
        printf("%d\t",*(*(arr+i)+j));
    }
    printf("\n");
    }
}

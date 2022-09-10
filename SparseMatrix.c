#include<stdio.h>
struct spMatrix
{
    int r;
    int c;
    int v;
};
typedef struct spMatrix spMatrix;

void main()
{
   
    int a[3][3], i, j, nz = 0; 
    spMatrix s[9];
    printf("\nEnter the array elements:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            scanf("%d" ,&a[i][j]);
            if(a[i][j] != 0)
            {
                s[nz].r = i;
                s[nz].c = j;
                s[nz].v = a[i][j];
                nz++;
            }
            

        }
    }
    printf("\nROW   COLUMN  NZ\n");
    for(i = 0; i < nz ; i++)
    {
        printf("\n%d       %d      %d\n", s[i].r, s[i].c, s[i].v);
    }

}
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if (n==2)
    {
        printf("*\n***\n  *");
        return 0;
    }
    printf("*\n");
    int i=2,j;
    int space = 0;
    while (i<2*n)
    {
        if (i<n) 
        {
            printf("*");
            for (j = 0; j < space;j++)
                printf(" ");
            printf("*\n");
        }
        else if (i>n)
            {
                for (j = 0; j < space;j++)
                    printf(" ");
                printf("*");
                for (j = 0; j < 2*n-3-space;j++)
                    printf(" ");
                if (i!=2*n-1) printf("*");
                printf("\n");
            }
            else 
            {
                for (j = 0; j < 2 * n - 1;j++)
                    printf("*");
                space = space + 1;
                printf("\n");
            }
        space++;
        i++;
    }
}

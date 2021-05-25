#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        {
            for (int i = 1; i <= n;i++)
                printf("* ");
            printf("\n");
        }
    printf("\n\n"); //H.Vuong Dac


    for (int i = 1; i <= n;i++)
        printf("* ");
    for (int i = 2; i < n;i++)
        {
            printf("\n*");
            for (int i = 1; i < n - 1;i++)
                printf("  ");
            printf(" *");
        }
    printf("\n");
    for (int i = 1; i <= n; i++)
            printf("* ");//H.Vuong Rong
    printf("\n\n");
    
    for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= n;j++)
                if (i==1||i==n||j==1||j==n)
                    printf("* ");
                else printf("  ");
            printf("\n");
        }
    
}
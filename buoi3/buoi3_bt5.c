#include<stdio.h>

int main()
{
    int n,m;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        {   
            for (int j = 1; j < (n*2);j++)
            {   if (j>n)
                    m = j - (j - n) * 2;
                else
                    m = j;
                if (i+m<=n)
                    printf(" ");
                else
                    printf("*");
            }
            printf("\n");
        }
}
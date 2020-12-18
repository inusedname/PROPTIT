#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n;i++)
        printf(" ");
    printf("*\n");
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j <= n - i;j++)
            {printf(" ");}
        printf("*");
        for (int q = 1; q <= (2 * i) - 3;q++)
            {printf("~");}
        printf("*\n");
    }
    for (int i = 1; i <= (n * 2) - 1;i++)
    {
        printf("*");
    }
}
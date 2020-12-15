#include <stdio.h>
int main ()
{
    int n,i;
    scanf("%d", &n);
    for (i = 1; i <= n;i++)
    {
        for (int j = 1; j <= i;j++)
            printf("* ");
        printf("\n");
    } //tamgiac vuong can
    printf("\n\n");
    for (i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n-i;j++)
            printf("   ");
        for (int t = 1; t <= (2 * i) - 1; t++)
            printf(" * ");
        printf("\n\n");
    }
    for (int j = 1; j <= n-1;j++)
            printf("   ");
    printf(" * ");
}
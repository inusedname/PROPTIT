#include <stdio.h>

int main()
{
    int n; //3
    scanf("%d", &n);
    int a[n + 1];
    int b[n + 1];
    a[1] = 1;
    int tmp = 2 * n - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j < i; j++)
            b[j] = a[j - 1] + a[j];
        for (int j = 2; j < i; j++)
            a[j] = b[j];
        a[i] = 1;
        for (int j = 0; 2 * j < tmp - (2 * i - 1);j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
        {    
            printf("%d ", a[j]);
        }
        printf("\n");
    }
}
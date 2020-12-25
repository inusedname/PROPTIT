#include <stdio.h>
int main()
{
    int a[100]={0,1};
    int n,i;
    scanf("%d", &n);
    for (i = 2; i < n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    for (i = 0; i < n;i++)
        printf("%d ", a[i]);
}
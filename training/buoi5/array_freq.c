#include <stdio.h>
int main()
{
    int a[100];
    int b[100]={0};
    int n, i;
    scanf("%d", &n);
    int temp;
    for (i = 0; i < n;i++)
    {
        scanf("%d", &a[i]);
        b[a[i]]++;
    }
    for (i = 0; i < n;i++)
    {
        printf("%d %d\n", a[i], b[a[i]]);
    }
}
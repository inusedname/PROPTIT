#include <stdio.h>
#include <math.h>
int nto(int i)
{
    if (i==1)
        return 0;
    int j;
    for (j = 2; j <= sqrt(i);j++)
    {
        if (i%j==0)
            return 0;
    }
    return 1;
}
int main()
{
    int n, i;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n;i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n;i++)
    {
        if (nto(a[i]))
            printf("%d ", a[i]);
    }
}
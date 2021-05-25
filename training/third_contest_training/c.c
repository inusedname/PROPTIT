#include <stdio.h>

int a[100000];
int f[1000000]={0};
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int max = 1;
    for (i = 0; i < n;i++)
    {
        scanf("%d", &a[i]);
        f[a[i]]++;
        if (a[i]>max)
            max = a[i];
    }
    int fir = 0, cfir = 0;
    for (i = 1; i <= max;i++)
    {
        if (f[i] >= cfir) 
        {
            fir = i;
            cfir = f[i];
        }
    }
    printf("%d %d", fir, cfir);
}
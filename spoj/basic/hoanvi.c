#include <stdio.h>
int fr[10];
int a[10];
int n;
void xuat(int a[], int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d", a[i]);
    printf("\n");
}
void dequi(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (!fr[i])
        {
            fr[i] = 1;
            a[k] = i;
            if (k == n)
                xuat(a, n);
            else
                dequi(k + 1);
            fr[i] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);
    dequi(1);
}
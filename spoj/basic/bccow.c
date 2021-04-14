#include <stdio.h>

int m, n, s = 0;
int smax = 0;
int a[16];
void dequi(int k) //81 61 58 42 33
{
    if (s > smax)
        smax = s;
    for (int i = k; i < n; i++)
    {
        if (s + a[i] <= m)
        {
            s += a[i];
            dequi(i + 1);
            s -= a[i];
        }
    }
}
int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    dequi(0);
    printf("%d", smax);
}
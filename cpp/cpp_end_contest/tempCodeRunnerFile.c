#include <stdio.h>

void solve(long long l, long long r, long long a[])
{
    int dem = 0;
    for (long long i = l; i <= r; i++)
    {
        if (a[i] == 1 || i == 4)
        {
            dem++;
            continue;
        }
        long long tmp = i;
        for (long long j = 2; j <= tmp; j++)
        {
            if (tmp % j == 0)
            {
                dem++;
                while (tmp % j == 0)
                {
                    tmp /= j;
                }
                if (a[tmp])
                {
                    dem++;
                    tmp = 1;
                    break;
                }
            }
        }
    }
    printf("%d\n", dem);
}

int main()
{
    int t;
    scanf("%d", &t);
    long long f[t], l[t];
    long long max = 0;
    for (int i = 0; i < t; i++)
    {
        scanf("%lld%lld", &f[i], &l[i]);
        if (l[i] > max)
            max = l[i];
    }
    long long a[max + 1];
    a[0] = 0;
    a[1] = 0;
    for (long long i = 2; i <= max; i++)
        a[i] = 1;
    for (long long i = 2; i * i <= max; i++)
    {
        if (a[i])
        {
            for (long long j = i * i; j <= max; j += i)
                a[j] = 0;
        }
    }
    for (int i = 0; i < t; i++)
    {
        solve(f[i], l[i], a);
    }
}
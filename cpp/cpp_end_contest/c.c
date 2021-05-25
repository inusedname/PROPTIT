#include <stdio.h>

void solve(int l, int r, int a[])
{
    int dem = 0;
    for (int i = l; i <= r; i++)
    {
        if (a[i] == 1 || i == 4)
        {
            dem++;
            continue;
        }
        int tmp = i;
        for (int j = 2; j <= tmp; j++)
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
    cout << dem << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int f[t], l[t];
    int max = 0;
    for (int i = 0; i < t; i++)
    {
        cin >> f[i] >> l[i];
        if (l[i] > max)
            max = l[i];
    }
    int a[max + 1];
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i <= max; i++)
        a[i] = 1;
    for (int i = 2; i * i <= max; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j <= max; j += i)
                a[j] = 0;
        }
    }
    for (int i = 0; i < t; i++)
    {
        solve(f[i], l[i], a);
    }
}
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int a[100001];
int timtong(int n)
{
    int sum1 = 0;
    while (n > 0)
    {
        sum1 += n % 10;
        n /= 10;
    }
    return sum1;
}
void solve()
{
    int n;
    cin >> n;
    if (a[n] == 0)
    {
        int sum1 = timtong(n);
        int sum2 = 0;
        int i = 2;
        int flag = 0;
        while (1)
        {
            while (n % i == 0)
            {
                sum2 += timtong(i);
                n /= i;
                if (a[n])
                {
                    sum2 += timtong(n);
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
            i++;
        }
        if (sum1 == sum2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int n = 100001;
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < n; i++)
        a[i] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j < n; j += i)
                a[j] = 0;
        }
    }
    while (t--)
        solve();
}
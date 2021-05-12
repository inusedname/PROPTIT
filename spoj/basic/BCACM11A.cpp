#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int ktrk(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int tmp = n % 10;
        if (tmp == 0)
            return 0;
        sum += tmp;
        n /= 10;
    }
    if (sum % 5 == 0)
        return 1;
    else
        return 0;
}
int ktrm(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int tmp = n % 10;
        sum += tmp;
        n /= 10;
    }
    if (sum % 5 == 0)
        return 1;
    else
        return 0;
}
void solve()
{
    int a[1000] = {0};
    int n, m, k;
    cin >> k >> m >> n;
    int i = 104;
    while (i < 1000)
    {
        if (k > 0 && ktrk(i) == 1)
        {
            a[i] = 1;
            k--;
        }
        if (a[i] == 0 && m > 0 && ktrm(i) == 1)
        {
            a[i] = 1;
            m--;
        }
        i++;
    }
    if (k)
    {
        cout << "NO";
        return;
    }
    if (m)
    {
        cout << "NO";
        return;
    }
    for (int i = 100; i < 1000 && n; i++)
        if (a[i] == 0)
            n--;
    if (n)
    {
        cout << "NO";
        return;
    }
    cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}
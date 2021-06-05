#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
void IN(int k, int a[])
{
    for (int i = 1; i <= k; i++)
        cout << a[i];
    cout << " ";
}
void solve()
{
    int n, k;
    cin >> n >> k;
    int a[k + 1];
    for (int i = 1; i <= k; i++)
        a[i] = i;
    IN(k, a);
    while (1)
    {
        int i = k;
        while (i >= 1 && a[i] == n - k + i)
            i--;
        if (i == 0)
            break;
        a[i]++;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;
        IN(k, a);
    }
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
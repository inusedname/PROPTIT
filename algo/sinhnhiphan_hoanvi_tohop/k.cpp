#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
int n;
void IN(string alpha, int a[])
{
    cout << alpha;
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << endl;
}
void solve()
{
    cin >> n;
    string alpha;
    for (int i = 1; i <= n; i++)
        alpha.push_back('A' + i - 1);
    // alpha.push_back('\0');
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = 1;
    IN(alpha, a);
    while (1)
    {
        int i = n;
        while (i > 0 && a[i] == n)
            i--;
        if (i == 0)
        {
            int j = n - 2;
            while (j >= 0 && alpha[j] > alpha[j + 1])
                j--;
            if (j < 0)
                return;
            for (int z = n - 1; z > j; z--)
                if (alpha[z] > alpha[j])
                {
                    swap(alpha[z], alpha[j]);
                    break;
                }
            int l = j + 1;
            int r = n - 1;
            while (l < r)
            {
                swap(alpha[l], alpha[r]);
                l++, r--;
            }
            for (int i = 1; i <= n; i++)
                a[i] = 1;
            IN(alpha, a);
            continue;
        }
        a[i]++;
        for (int j = i + 1; j <= n; j++)
            a[j] = 1;
        IN(alpha, a);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}
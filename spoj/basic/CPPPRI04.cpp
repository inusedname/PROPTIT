#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

void solve()
{
    int t;
    cin >> t;
    int test[t];
    int max = 1;
    for (int i = 0; i < t; i++)
    {
        cin >> test[i];
        if (test[i] > max)
            max = test[i];
    }
    int n = max;
    n++;
    int sto[n];
    sto[0] = 0;
    sto[1] = 0;
    for (int i = 2; i < n; i++)
        sto[i] = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (sto[i])
        {
            for (int j = i * i; j < n; j += i)
                sto[j] = 0;
        }
    }
    max++;
    int ans[max];
    ans[1] = 1;
    for (int i = 2; i < max; i += 2)
        ans[i] = 2;
    for (int i = 3; i < max; i += 2)
    {
        if (sto[i])
            ans[i] = i;
        else
        {
            for (int j = 3; j <= sqrt(i); j++)
                if (i % j == 0)
                {
                    ans[i] = j;
                    break;
                }
        }
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 1; j <= test[i]; j++)
            cout << ans[j] << " ";
        cout << endl;
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
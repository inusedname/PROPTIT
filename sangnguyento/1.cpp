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
    int n = 100;
    n++;
    int a[n];
    a[0] = 0;
    a[1] = 0; 
    for (int i = 2; i < n;i++)
        a[i] = 1; 
    for (int i = 2; i * i <= n; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j < n; j += i)
                a[j] = 0;
        }
    }
    for (int i = 2; i < n;i++)
        if (a[i])
            cout << i << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) 
        solve();
}
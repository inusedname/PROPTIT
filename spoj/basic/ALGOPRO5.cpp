#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
typedef double db;
#define endl "\n";

void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    ll sumtmp = 1;
    for (int i = 1; i <= n; i++)
    {
        sumtmp *= 2;
        sum += sumtmp;
    }
    cout << sum;
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
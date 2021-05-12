#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
ll fibo[93];
void solve()
{
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        cout << fibo[tmp] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 3; i < 93; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    // while (t--)
    {
        solve();
    }
}
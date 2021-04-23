#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int sto[10001];

void solve()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        if (sto[i])
            cout << i << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 10000;
    n++;
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
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}
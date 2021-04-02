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
    int n;
    cin >> n;
    vector<int> b(n);
    int tmp;
    int max = -9999;
    for (int i = 0; i < n;i++)
    {
        cin >> tmp;
        b[i] = tmp;
        if (max<tmp)
            max = tmp;
    }
    max++;
    int a[max];
    a[0] = 0;
    a[1] = 0;
    for (int i = 2; i < max; i++)
        a[i] = 1;
    for (int i = 2; i * i <= max; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j < max; j += i)
                a[j] = 0;
        }
    }
    int dem = 0;
    for (int i = 0; i < n;i++)
    {
        if (a[b[i]])
            dem++;
    }
    cout << dem;
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
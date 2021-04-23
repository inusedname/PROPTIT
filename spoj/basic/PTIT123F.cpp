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
    vector<int> mark;
    mark.resize(n + 1, 1);
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
            if (mark[j])
                mark[j] = 0;
            else
                mark[j] = 1;
    }
    int dem = 0;
    for (int i = 1; i <= n; i++)
        if (mark[i])
            dem++;
    cout << dem;
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
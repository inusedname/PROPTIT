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
    int n, m;
    cin >> n >> m;
    int pp[n];
    for (int i = 0; i < n; i++)
        cin >> pp[i];
    int freq[10] = {0};
    int tmp;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        freq[tmp]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (freq[pp[i]])
            cout << pp[i] << " ";
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
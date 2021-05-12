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
    int n, s, t = 0, A[202], L[100];
    cin >> n >> s;
    for (int i = 0; i < n;i++)
        cin >> A[i];
    for (int i = 0; i <= n;i++)
        for (t = s; t >= A[i];t--)
            if (L[t])
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
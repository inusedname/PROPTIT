#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;

vector<ll> L;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        L.clear();
        L.resize(n + 5);
        L[0] = 1;
        L[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            L[i] = (2 * L[i - 1]) % oo;
            if (i - k - 1 >= 0)
                L[i] = L[i] - L[i - k - 1];
            if (L[i] < 0)
                L[i] += oo;
        }
        cout << L[n];
        cout << endl;
    }
}
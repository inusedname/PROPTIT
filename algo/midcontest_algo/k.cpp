#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
#define endl "\n"
#define pi pair<int, int>
#define pll pair<ll, ll>
const int oo = 1e9;
const int MOD = 1e9 + 7;

using namespace std;

void solve()
{
    int n, tmp;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a[i] = tmp;
        b[i] = tmp;
    }
    sort(b.begin(), b.end());
    int start = 0, end = n - 1;
    while (a[start] == b[start])
        start++;
    cout << start + 1 << " ";
    while (a[end] == b[end])
        end--;
    cout << end + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}
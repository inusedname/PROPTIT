#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
vector<int> v;
vector<int> u;
bool cmp(int x, int y)
{
    return x > y;
}
void solve()
{
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    u.resize(n);
    u = v;
    sort(v.begin(), v.end());
    sort(u.begin(), u.end(), cmp);
    int demv = 0, demu = 0;
    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            cout << u[demu++] << " ";
        else
            cout << v[demv++] << " ";
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
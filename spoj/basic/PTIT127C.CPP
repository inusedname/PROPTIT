#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

struct meet
{
    int s;
    int f;
};
bool cmp(meet x, meet y)
{
    if (x.s == y.s)
        return (x.f - x.s < y.f - y.s);
    return (x.s < y.s);
}
void solve()
{
    int n;
    cin >> n;
    vector<meet> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].s >> a[i].f;
    sort(a.begin(), a.end(), cmp);
    int max = 1;
    for (int i = 0; i < n; i++)
    {
        int tmp = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].f <= a[j].s)
            {
                tmp++;
                a[i].f = a[j].f;
            }
        }
        if (tmp > max)
            max = tmp;
    }
    cout << max;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
}
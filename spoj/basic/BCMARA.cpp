#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

struct mem
{
    int h;
    int m;
    int s;
};
bool cmp(mem x, mem y)
{
    if (x.h == y.h)
    {
        if (x.m == y.m)
            return x.s < y.s;
        return x.m < y.m;
    }
    return x.h < y.h;
}
void solve()
{
    int n;
    cin >> n;
    vector<mem> list(n);
    for (int i = 0; i < n; i++)
        cin >> list[i].h >> list[i].m >> list[i].s;
    sort(list.begin(), list.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << list[i].h << " " << list[i].m << " " << list[i].s << endl;
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
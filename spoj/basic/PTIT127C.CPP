#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
int n;

int dem = 0;
struct meet
{
    int s;
    int f;
};
vector<meet> a(n);
bool cmp(meet x, meet y)
{
    return (x.f <= y.f);
}

void dequi()
{
    int x = a[0].s;
    for (int i = 0; i < n; i++)
    {
        if (x <= a[i].s)
        {
            dem++;
            x = a[i].f;
        }
    }
}
void solve()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].s >> a[i].f;
    sort(a.begin(), a.end(), cmp);
    dequi();
    cout << dem;
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
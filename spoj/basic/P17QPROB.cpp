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
bool cmp(string x, string y)
{
    if (x + y < y + x)
        return 1;
    else
        return 0;
}
void solve()
{
    cin >> n;
    cin.ignore();
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << a[i];
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
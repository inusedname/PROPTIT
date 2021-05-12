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
    ll a, b, c;
    cin >> a >> b >> c;
    cout << max(max(a, b), c) - min(min(a, b), c);
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
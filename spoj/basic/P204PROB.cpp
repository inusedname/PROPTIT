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
    ll n;
    cin >> n;
    ll chan = n, le = n;
    if (n % 2 == 0)
        le--;
    else
        chan--;
    ll nchan = chan / 2;
    ll nle = (le + 1) / 2;
    cout << (nchan * (nchan + 1)) - (nle * nle);
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
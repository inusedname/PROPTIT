#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
typedef double db;
#define endl "\n";

void solve()
{
    ll n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        n /= 1000;
        if (n < 1000)
            cout << n * 1000;
        else if (n < 5000)
            cout << n * 900;
        else
            cout << n * 800;
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
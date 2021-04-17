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
    cin >> n;
    if (n == 6 || n == 28 || n == 496 || n == 8128 || n == 33550336 || n == 8589869056 || n == 137438691328)
        cout << "1\n";
    else
        (cout << "0\n");
}
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t;
        cin >> t;
        while (t--)
            solve();
    }
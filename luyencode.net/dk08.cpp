#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

#define ll long long
#define endl "\n"
#define vi vector<int>
#define vll vector<ll>
#define vii pair<int, int>
#define v2ll pair<ll, ll>
const int oo = 1e9;
const int MOD = 1e9 + 7;
using namespace std;

void solve()
{
    double a, b;
    char c;
    cin >> a >> c >> b;
    cout << fixed << setprecision(2);
    if (c == '+')
        cout << a + b;
    else if (c == '-')
        cout << a - b;
    else if (c == '*')
        cout << a * b;
    else if (b)
        cout << a / b;
    else
        cout << "Math Error";
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
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
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b + c)
        cout << a << "=" << b << "+" << c;
    else if (a == b - c)
        cout << a << "=" << b << "-" << c;
    else if (a == b * c)
        cout << a << "=" << b << "*" << c;
    else if (a == b / c)
        cout << a << "=" << b << "/" << c;
    else if (a + b == c)
        cout << a << "+" << b << "=" << c;
    else if (a - b == c)
        cout << a << "-" << b << "=" << c;
    else if (a * b == c)
        cout << a << "*" << b << "=" << c;
    else if (a / b == c)
        cout << a << "/" << b << "=" << c;
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
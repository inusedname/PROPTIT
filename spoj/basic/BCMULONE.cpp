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
    int n;
    cin >> n;
    for (int i = 1; i <= (n - 1) / 9; i++)
        cout << "123456790";
    int t = (n - 1) % 9;
    for (int i = 1; i <= t; i++)
        cout << (char)(48 + i);
    if ((n - 1) / 9 == 0)
        for (int i = t + 1; i >= 1; i--)
            cout << (char)(48 + i);
    for (int i = 1; i <= (n - 1) / 9; i++)
        cout << "0987654321";
    cout << endl;
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
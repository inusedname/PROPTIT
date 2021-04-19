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
    string s = "", s1 = "1234567900", s2 = "098765432";
    int n1 = (n - 1) / 9, n2 = n - 9 * n1;
    for (int i = 1; i <= n2; i++)
    {
        s.insert(s.size(), 1, (char)(i + '0'));
    }
    for (int i = n2 - 1; i > 0; i--)
    {
        s.insert(s.size(), 1, (char)(i + '0'));
    }
    if (n > 9)
    {
        for (int i = 0; i < n1; i++)
            s.insert(0, s1);
        for (int i = 0; i < n1; i++)
            s.insert(s.size() - 1, s2);
    }
    cout << s << endl;
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
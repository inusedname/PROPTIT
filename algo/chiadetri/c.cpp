#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
void solve()
{
    int n, k;
    string s1, s2, s;
    s1.clear();
    s2.clear();
    cin >> n >> k;
    s1 = "A";
    s2 = "B";   
    for (int i = 0; i < n; i++)
    {
        s = s2;
        s2 = s1 + s2;
        s1 = s;
    }
    if (k <= s2.size())
        cout << s2[k - 1];
    else if (k <= s2.size() + s1.size())
        cout << s1[k - s2.size() - 1];
    else
        cout << s2[k - 2 * s2.size() - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}
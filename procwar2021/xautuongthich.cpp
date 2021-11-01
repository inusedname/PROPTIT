#include <bits/stdc++.h>
#define ll long long
#define arraycin(n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;
bool check(string a, string b)
{
    if (a == b)
        return 1;
    if (a.size() % 2)
        return 0;
    int l = a.size() / 2;
    string a1 = a.substr(0, l);
    string a2 = a.substr(l, l);
    string b1 = b.substr(0, l);
    string b2 = b.substr(l, l);
    return (check(a1, b1) && check(a2, b2)) || (check(a1, b2) && check(a2, b1));
}
void solve()
{
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size())
    {
        cout << "NO";
        return;
    }
    if (check(a, b))
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}
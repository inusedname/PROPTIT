#include <bits/stdc++.h>
#define ll long long
#define arraycin(n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define endl "\n"
const int oo = 1e9 + 7;
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int boy = 0, girl = 0;
    string u = "";
    char c = 0;
    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (c == 0)
            c = s[i];
        else if (s[i] != c)
        {
            num += 2;
            c = 0;
        }
    }
    if (c)
        num++;
    int n = log2(num) + 1;
    bool a[n] = {0};
    while (num)
    {
        int tmp = log2(num);
        a[tmp] = 1;
        num -= pow(2, tmp);
    }
    for (int i = n - 1; i >= 0; i--)
        cout << a[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}
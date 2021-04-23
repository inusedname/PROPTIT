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
    while (1)
    {
        int n;
        cin >> n;
        if (!n)
            return;
        string s1, s2, s;
        cin >> s1 >> s2 >> s;
        if (s1 + s2 == s)
        {
            cout << "0\n";
            continue;
        }
        int dem = 0;
        while (dem < 50)
        {
            int demtmp = 0;
            string tmp;
            for (int i = 0; i < n; i++)
                tmp = tmp + s2[i] + s1[i];
            if (tmp == s)
            {
                cout << dem + 1 << endl;
                break;
            }
            s1 = tmp.substr(0, n);
            s2 = tmp.substr(n, n);
            dem++;
        }
        if (dem > 49)
            cout << "-1" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    {
        solve();
        cout << endl;
    }
}
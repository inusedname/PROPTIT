#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";
struct fibo
{
    ll val;
    int stat;
};
void solve()
{
    int t;
    cin >> t;
    vector<fibo> list(t);
    ll max = 0;
    ll srt[t];
    ll tmp;

    for (int i = 0; i < t; i++)
    {
        cin >> tmp;
        srt[i] = tmp;
        list[i].val = tmp;
        list[i].stat = 0;
        if (tmp > max)
            max = tmp;
    }
    sort(srt, srt + t);
    ll a0 = 0;
    ll a1 = 1;
    tmp = 0;
    int dem = 0;
    while (tmp <= max)
    {
        tmp = a0 + a1;
        while (tmp > srt[dem])
            dem++;
        if (tmp == srt[dem])
        {
            for (int i = 0; i < t; i++)
                if (list[i].val == tmp)
                    list[i].stat = 1;
        }
        a0 = a1;
        a1 = tmp;
    }
    for (int i = 0; i < t; i++)
        if (list[i].val == 0)
            list[i].stat = 1;
    for (int i = 0; i < t; i++)
    {
        if (list[i].stat)
            cout << "YES\n";
        else
            cout << "NO\n";
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
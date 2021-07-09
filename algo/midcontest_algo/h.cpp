#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#define ll long long
#define endl "\n"
#define pi pair<int, int>
#define pll pair<ll, ll>
const int oo = 1e9;
const int MOD = 1e9 + 7;

using namespace std;
char s;
vector<int> noti;
void solve()
{
    int tmp;
    while (1)
    {
        cin >> s;
        if (s == 'E')
            break;
        if (s == '1')
        {
            cin >> tmp;
            noti.push_back(tmp);
            cout << "NEW\n";
        }
        else
        {
            for (int i = 0; i < noti.size(); i++)
                cout << noti[i] << " ";
            cout << endl;
            noti.clear();
            noti.resize(0);
        }
    }
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
    }
}
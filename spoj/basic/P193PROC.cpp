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
    string s;
    cin >> s;
    int dem = 0;
    int dophuctap = 0;
    int c[160] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        c[s[i]]++;
        if (c[s[i]] == 1)
            dophuctap++;
    }
    if (dophuctap > 2)
    {
        int k = 1;
        while (1)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (c[s[i]] == k)
                {
                    dem += k;
                    dophuctap--;
                    c[s[i]] = 0;
                }
                if (dophuctap < 3)
                {
                    break;
                }
            }
            if (dophuctap < 3)
            {
                break;
            }
            k++;
        }
    }
    cout << dem;
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
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
    int dem = 1;
    while (1)
    {
        string s1, s2;
        cin >> s1;
        cin.ignore();
        cin >> s2;
        if (s1 == s2 && s1 == "END")
        {
            break;
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2)
            printf("Case %d: same\n", dem);
        else
            printf("Case %d: different\n", dem);
        dem++;
    }
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
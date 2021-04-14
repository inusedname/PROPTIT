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
    int i;
    for (i = s.size() - 1; i > 0; i--)
    {
        if (s[i] > s[i - 1])
            break;
    }
    i--;
    if (i < 0)
    {
        cout << "0";
        return;
    }
    for (int j = s.size() - 1; j > i; j--)
    {
        if (s[j] > s[i])
        {
            char k = s[j];
            s[j] = s[i];
            s[i] = k;
            break;
        }
    }
    sort(s.begin() + i + 1, s.end());
    cout << s;
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
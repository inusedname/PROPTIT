#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n";

char tactic(char s1, char s2)
{
    if (s1 == 'B')
    {
        if (s2 == 'K')
            return 'B';
        else
            return 'G';
    }
    if (s1 == 'K')
    {
        if (s2 == 'G')
            return 'K';
        else
            return 'B';
    }
    if (s1 == 'G')
    {
        if (s2 == 'B')
            return 'G';
        else
            return 'K';
    }
}
void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin.ignore();
    cin >> s1;
    cin.ignore();
    cin >> s2;
    for (int i = 0; i < n; i++)
    {
        cout << tactic(s1[i], s2[i]);
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
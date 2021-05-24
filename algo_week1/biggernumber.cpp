#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
#define endl "\n"
string s1, s2;

bool cmp(char x, char y)
{
    return x > y;
}
void solve()
{
    cin >> s1 >> s2;
    sort(s2.begin(), s2.end(), cmp);
    int p = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (p < s2.size() && s1[i] < s2[p])
            cout << s2[p++];
        else
            cout << s1[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}
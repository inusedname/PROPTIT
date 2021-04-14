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
    int dem = 1;
    char tmp = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == tmp)
        {
            dem++;
        }
        else
        {
            cout << dem << tmp;
            tmp = s[i];
            dem = 1;
        }
    }
    cout << dem << tmp;
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
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
    int n;
    cin >> n;
    vector<string> s(2);
    s[0] = "0";
    s[1] = "1";
    int i = 0;
    while (s.size() < pow(2, n))
    {
        int b = s.size();
        for (int i = 0; i < b; i++)
        {
            s.push_back("1" + s[i]);
            s[i] = "0" + s[i];
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
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